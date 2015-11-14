#include "stdafx.h"
#include "bio_db_io.hpp"


#include "bio_person_table.hpp"
#include "bio_location_table.hpp"
#include "bio_photo_item_table.hpp"
#include "bio_visitor_table.hpp"

namespace SmartBio
{
	namespace Data
	{
		bool BioDbIO::initilalized = false;
		std::string BioDbIO::CONNECTION_STRING;
		std::map<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> BioDbIO::table_queries_;

		void BioDbIO::setConnectionString(std::string connection_string)
		{
			CONNECTION_STRING = connection_string;
		}

		void BioDbIO::initilalize()
		{
			if (!initilalized)
			{
				Poco::SharedPtr<BioPersonTable>    pp = new BioPersonTable();
				Poco::SharedPtr<BioLocationTable>  lt = new BioLocationTable();
				Poco::SharedPtr<BioPhotoItemTable> pit = new BioPhotoItemTable();
				Poco::SharedPtr<BioVisitorTable>   vt = new BioVisitorTable();


				std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> person_pair(BioPersonTable::TABLE_NAME, pp);
				std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> location_pair(BioLocationTable::TABLE_NAME, lt);
				std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> photo_item_pair(BioPhotoItemTable::TABLE_NAME, pit);
				std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> visitor_pair(BioVisitorTable::TABLE_NAME, vt);


				table_queries_.insert(person_pair);
				table_queries_.insert(location_pair);
				table_queries_.insert(photo_item_pair);
				table_queries_.insert(visitor_pair);



				Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, CONNECTION_STRING);

				for (auto it = table_queries_.begin(); it != table_queries_.end(); ++it)
				{
					Poco::SharedPtr<Interfaces::ITableQuery> qtable = (*it).second;
					std::string create_table_query = qtable->createTable();
					std::cout << create_table_query << std::endl;

					Poco::Data::Statement stmt((tmp << create_table_query, Poco::Data::Keywords::now));
					Poco::Data::Statement::Result result = stmt.executeAsync();
					result.wait();
				}

				initilalized = true;
				tmp.close();
			}
		}
	}
}