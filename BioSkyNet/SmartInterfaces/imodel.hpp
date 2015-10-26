#ifndef IModel_INCLUDED
#define IModel_INCLUDED

#include "patterns.hpp"

#include <Poco/NotificationCenter.h>

namespace SmartBio { namespace Interfaces 
{	
	class IModel : private Uncopyable, public Poco::NotificationCenter
	{		
	public:
		virtual ~IModel() {};

		void initialize()
		{
			do_initialize();
		}
		
	protected:
		IModel() {};
	private:			

		bool initialized_;
		virtual void do_initialize() = 0;	

	};

} }

#endif
