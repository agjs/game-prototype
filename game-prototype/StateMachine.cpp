#include "StateMachine.h"


namespace GamePrototype {

	void StateMachine::AddState(StateRef_t newState, bool isReplacing) {
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState); // std::move ?
	}


	void StateMachine::RemoveState() {
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges() {
		if (this->_isRemoving && !this->_states.empty()) {
			this->_states.pop();

			if (!this->_states.empty()) {
				this->_states.top()->Resume(); // .top ? -> Resume() ?
			}

			this->_isRemoving = false;

			if (this->_isAdding) {
				if (!this->_states.empty()) {
					if (this->_isReplacing) {
						this->_states.pop();
					}
					else {
						this->_states.top()->Pause();
					}
				}
				this->_states.push(std::move(this->_newState));
				this->_states.top()->Init();
				this->_isAdding = false;
			}
		}
	}

	StateRef_t& StateMachine::GetActiveState() {
		return this->_states.top();
	}

	StateMachine::StateMachine()
	{
	}


	StateMachine::~StateMachine()
	{
	}
}