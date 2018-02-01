package components.body.automaton.transition.guards;

import components.body.automaton.transition.guards.Number;

component GuardIsBoolean {

	port
		in Number input;

	automaton GuardIsNotBooleanAutomaton {
		state A,B;
		initial A;

		A -> B [input.get()==0];
	}
}