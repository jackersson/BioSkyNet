#include "stdafx.h"
#include "bio_person_db_io.hpp"

//using namespace Poco::Data::b;
using namespace Poco::Data::Keywords;
namespace SmartBio
{
	namespace Data
	{		
		BioPersonDbIO::BioPersonDbIO( std::string connection_string) 
		                            : connection_string_(connection_string)	
		{			
		  initialize();
			std::cout << "constructed" << std::endl;
		}

		void BioPersonDbIO::initialize()
		{
			try
			{
				Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, connection_string_);
				std::vector<std::string> query;
				
				query.push_back("CREATE TABLE IF NOT EXISTS [bio_subjects]");
				query.push_back(" ( ");
				query.push_back(" Id INTEGER PRIMARY KEY ");
				query.push_back(" , FirstName ntext NOT NULL");
				query.push_back(" , LastName ntext NOT NULL");
				query.push_back(" , DateOfBirth datetime NOT NULL");
				query.push_back(" , Gender tinyint NOT NULL");
				query.push_back(" , Country ntext NOT NULL");
				query.push_back(" , City ntext NOT NULL");
				query.push_back(" , Photo ntext NOT NULL");
				query.push_back(" , Comment ntext NOT NULL");
				query.push_back(" );");
				
				std::string qcreate_table_ = Poco::cat(std::string(""), query.begin(), query.end());

				Poco::Data::Statement stmt((tmp << qcreate_table_, Poco::Data::Keywords::now));

				Poco::Data::Statement::Result result = stmt.executeAsync();

				result.wait();

				tmp.close();
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		BioPersonDbIO::~BioPersonDbIO()
		{

		}


		bool BioPersonDbIO::write(std::vector<PersonType>& data)
		{
			try
			{
				Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, connection_string_);

				int unique(0);
				tmp << bioPersonUnique(), into(unique), now;

				for (auto it = data.begin(); it != data.end(); ++it)
					(*it).setIndex(++unique);
							
				Poco::Data::Statement stmt((tmp << bioPersonInsert(), use(data), now));

				Poco::Data::Statement::Result result = stmt.executeAsync();

				result.wait();



				return true;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}

			return false;
		}
		
		bool BioPersonDbIO::read(std::vector<BioPerson>& data, std::string query)
		{
			try
			{
				if (query == "")
					query = bioPersonSelect();

				Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, connection_string_);
				
				Poco::Data::Statement stmt((tmp << query, into(data), async, now));

				Poco::Data::Statement::Result result = stmt.executeAsync();

				result.wait();

				return true;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}

			return false;
		}

		bool BioPersonDbIO::write( BioPerson& data )
		{
			try
			{
				Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, connection_string_);
				
				int unique(0);

				tmp << bioPersonUnique(), into(unique), now;
				++unique;
				++unique;
				data.setIndex(++unique);	

				Poco::Data::Statement stmt((tmp << bioPersonInsert(), use(data), now));

				/*Poco::Data::Statement::Result result = */stmt.execute();

				/*result.wait();*/


				return true;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}

			return false;
		}		
	
	}
}

