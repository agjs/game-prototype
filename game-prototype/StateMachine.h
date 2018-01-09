#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace GamePrototype {

	typedef std::unique_ptr<State> StateRef_t;

	class StateMachine {
	public:
		StateMachine();
		~StateMachine();
		void AddState(StateRef_t newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		StateRef_t& GetActiveState();

	private:
		std::stack<StateRef_t> _states;
		StateRef_t _newState;
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};

};

/*
	What is typedef ? 
	StateMachine pattern ?
	unique_ptr ?
*/