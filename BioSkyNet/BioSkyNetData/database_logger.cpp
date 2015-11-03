#include "stdafx.h"
#include "database_logger.hpp"

namespace SmartBio { namespace Model 
{
	//"F:\\SmartProjects\\SmartBio\\SmartBio\\database\\smart_biometrics.db"
	DatabaseLogger::DatabaseLogger( std::string const& database_path
		                            , std::string const& table_name
																, std::string const& source_name ) 
		                            : database_path_( database_path )
																, table_name_( table_name )
																, source_name_( source_name )
																, active_( false )
	{
		initialize();
	}

	DatabaseLogger::~DatabaseLogger(){}

	void DatabaseLogger::do_initialize()
	{
		/*try
		{
			channel_ = new Poco::Data::SQLChannel( Poco::Data::SQLite::Connector::KEY
			                                     , database_path_, source_name_ );
			channel_->setProperty( "table", table_name_ );

			logger_ = &Poco::Logger::create( source_name_, channel_, Poco::Message::PRIO_INFORMATION );

			active_ = true;
		}
		catch ( Poco::Data::SQLite::InvalidSQLStatementException& e )
		{			
			postNotification( new ErrorNotification( e.what() ) );
		}
		catch ( Poco::Data::SQLite::SQLiteException& e )
		{
			postNotification( new ErrorNotification( e.what() ) );
		}		*/
	}

	void  DatabaseLogger::do_post( std::string const& message, int priority   )
	{
	/*	Poco::Mutex::ScopedLock lock( mutex_ );
		try
		{
			switch ( priority )
			{
			case Poco::Message::PRIO_CRITICAL:
				logger_->critical( message );
				break;
			case Poco::Message::PRIO_DEBUG:
				logger_->debug( message );
				break;
			case Poco::Message::PRIO_ERROR:
				logger_->error( message );
				break;
			case Poco::Message::PRIO_FATAL:
				logger_->fatal( message );
				break;
			case Poco::Message::PRIO_INFORMATION:
				logger_->information( message );
				break;
			case Poco::Message::PRIO_WARNING:
				logger_->warning( message );
				break;
			case Poco::Message::PRIO_TRACE:
				logger_->trace( message );
				break;
			default:
				logger_->information( message );
				break;
			}		
		}
		catch ( Poco::Data::SQLite::InvalidSQLStatementException& e )
		{			
			postNotification( new ErrorNotification( e.what() ) );
		}
		catch ( Poco::Data::SQLite::SQLiteException& e )
		{
			postNotification( new ErrorNotification( e.what() ) );
		}	*/	
	}


} }