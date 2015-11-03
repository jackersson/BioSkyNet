#ifndef Database_Logger_INCLUDED
#define Database_Logger_INCLUDED

#include "../SmartInterfaces/ilogger.hpp"

namespace SmartBio { namespace Model 
{

	class DatabaseLogger : public Interfaces::ILogger
	{
	public:	
		DatabaseLogger( std::string const& database_path
			            , std::string const& table_name
			            , std::string const& source_name ) ;
		~DatabaseLogger();
					
		bool isActive() const
		{
			return active_;
		}

	private:	
		bool active_;

		std::string source_name_  ;
		std::string table_name_   ;
		std::string database_path_;

	private:		
		Poco::AutoPtr<Poco::Data::SQLChannel> channel_;
		Poco::AutoPtr<Poco::Logger>           logger_  ;		

		void do_post( std::string const& message, int priority ) final;
		void do_initialize() final;
	};

} }


#endif