#ifndef IBiometrics_INCLUDED
#define IBiometrics_INCLUDED

#include "patterns.hpp"

namespace SmartBio { namespace Interfaces 
{	

	class IBiometrics : private Uncopyable
	{		
	public:		
		virtual ~IBiometrics() {};

		void activate()
		{
			do_activate();
		}

		bool activated() const
		{
			return activated_;
		}

	protected:
		IBiometrics():activated_( true ) {};	

	protected:
		bool activated_;

	private:		
	
		virtual void do_activate() = 0;	

	};

} }

#endif
