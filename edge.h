#ifndef EDGE_H_
#define EDGE_H_

#include "Arduino.h"

// #define DEBUG


#ifdef DEBUG
#	define DBG_PRINTLN(a,b)	{Serial.print(a);Serial.println(b);}
#else
#	define DBG_PRINTLN(a,b)	{}
#endif

#ifdef __cplusplus

namespace edge::STATE {
	uint8_t FALSE = 0;
	uint8_t TRUE = !FALSE;
}
template <class T>
class Edge {
		T previous0to1;
		T previous1to0;
		T previousChange;
  public:
    Edge ()
    {
      this->init(0);
    }
    Edge (T variable)
    {
      this->init(variable);
    }

		uint8_t rising(T variable) {
			uint8_t  ret = (variable != edge::STATE::FALSE && this->previous0to1 == edge::STATE::FALSE);
			this->previous0to1 = variable;

			if(ret != edge::STATE::FALSE )
				this->previous1to0 = edge::STATE::FALSE;
			
			return ret;
		}

		uint8_t falling(T variable) {
			uint8_t  ret = (variable == edge::STATE::FALSE && this->previous1to0 != edge::STATE::FALSE);
			this->previous1to0 = variable;
			if(ret == edge::STATE::FALSE )
				this->previous0to1 = !edge::STATE::FALSE;
			return ret;
		}

		uint8_t changing(T variable){
			uint8_t  ret = (variable != this->previousChange);
			if(ret != 0)
				this->previousChange = variable;
			return ret;
		}

		void init(T variable) {
			this->previous0to1 = variable;
			this->previous1to0 = variable;
			this->previousChange = variable;
		}
};



#endif /* __cplusplus */

#endif /* EDGE_H_ */