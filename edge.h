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
		T previous;
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
			uint8_t  ret = (variable != edge::STATE::FALSE && this->previous == edge::STATE::FALSE);
			this->init(variable);
			return ret;
		}

		uint8_t falling(T variable) {
			uint8_t  ret = (variable == edge::STATE::FALSE && this->previous != edge::STATE::FALSE);
			this->init(variable);
			return ret;
		}

		uint8_t changing(T variable){
			uint8_t  ret = (variable == edge::STATE::FALSE && this->previous != edge::STATE::FALSE) || \
										 (variable != edge::STATE::FALSE && this->previous == edge::STATE::FALSE);
			this->init(variable);
			return ret;
		}

		void init(T variable) {
			this->previous = variable;
		}
};

#endif /* __cplusplus */

#endif /* EDGE_H_ */