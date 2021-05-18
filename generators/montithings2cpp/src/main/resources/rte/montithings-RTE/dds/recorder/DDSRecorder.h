/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
// (c) https://github.com/MontiCore/monticore
#pragma once

#include <ace/OS_NS_stdlib.h>
#include <algorithm>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <future>
#include <iostream>
#include <unordered_map>
#include <utility>

#include "../../json/json.hpp"
#include "../../tl/optional.hpp"
#include "../../easyloggingpp/easylogging++.h"
#include "../message-types/DDSMessageTypeSupportImpl.h"
#include "../message-types/DDSRecorderMessageTypeSupportImpl.h"
#include "../../DDSClient.h"
#include "DDSCommunicator.h"
#include "HWCInterceptor.h"
#include "VectorClock.h"
#include "utils.h"

#define LOG_ID "RECORDER"

class DDSRecorder {
private:
    std::mutex sentMutex;

    int recorderMessageId = 0;

    DDSCommunicator ddsCommunicator;
    DDSClient *ddsClient;

    std::string instanceName;
    std::string topicName;
    std::string portName;


    // key = <message id>, value = <sent timestamp>
    using unackedMap = std::unordered_map<long, long long>;
    unackedMap unackedMessageTimestampMap;
    unackedMap unackedRecordedMessageTimestampMap;

    // key = <message id>, value = { key = <port instance id>, value = <delay>}
    using unsentDelayMap = std::unordered_map<long, std::pair<std::string, long long>>;
    unsentDelayMap unsentMessageDelays;
    unsentDelayMap unsentRecordMessageDelays;

    bool isOutgoingPort();

    void start();

    void stop();

    void sendInternalRecords();

    void sendState(json state);

    void onCommandMessage(const DDSRecorderMessage::Command &message);

    void onAcknowledgementMessage(const DDSRecorderMessage::Acknowledgement &message);

    static void handleAck(unackedMap &unackedMap,
                          unsentDelayMap &unsentDelayMap,
                          const char *sendingInstance,
                          long ackedId);

public:
    DDSRecorder() = default;

    ~DDSRecorder() = default;

    void init();

    void setInstanceName(const std::string &name);

    void setDDSClient(DDSClient &client);

    void initParticipant(int argc, char *argv[]);

    void setTopicName(const std::string &name);

    void setPortName(const std::string &name);

    void
    recordMessage(DDSMessage::Message message, const char *topicName, const vclock &vectorClock, bool includeContent);
};