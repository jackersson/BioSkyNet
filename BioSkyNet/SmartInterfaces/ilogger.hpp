#ifndef ILOGGER_HEADER
#define ILOGGER_HEADER

#include "patterns.hpp"

#include <Poco/NotificationCenter.h>
#include <Poco/Logger.h>

namespace SmartBio { namespace Interfaces 
{	
  class ILogger : public Poco::NotificationCenter, private Uncopyable
  {
  public:
  
		ILogger( void ) {};		
		virtual ~ILogger() {};		
		
  	void post( std::string const& message, int priority )
  	{
  		do_post( message, priority );				
  	}  	
		
	protected:
		Poco::Mutex   mutex_; 

		void initialize()
		{
			do_initialize();
		}
  
  private:	
		virtual void do_initialize() = 0;  
		virtual void do_post( std::string const& message, int priority ) = 0;  
  };

}}

#endif