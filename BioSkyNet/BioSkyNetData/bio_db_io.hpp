#ifndef Bio_DB_IO_INCLUDED
#define Bio_DB_IO_INCLUDED

//#include "idatabase_io.hpp"
//#include "bio_person_binder.hpp"
#include "bio_person_table.hpp"
#include "bio_person_binder.hpp"

#include "bio_location_table.hpp"
#include "bio_location_binder.hpp"

#include "bio_photo_item_table.hpp"
#include "bio_photo_item_binder.hpp"

#include "bio_visitor_table.hpp"
#include "bio_visitor_binder.hpp"

#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		using namespace Poco::Data::Keywords;
		
		class BioDbIO //: public SmartBio::Interfaces::IDatabaseIO<DataType>
		{
		public:
			BioDbIO(std::string connection_string)
			{
				CONNECTION_STRING = connection_string;
				initilalize();
			}
			~BioDbIO(){}

			template <typename DataType, typename TableType>
			bool write(DataType& data)
			{
				try
				{					
					auto it = table_queries_.find(TableType::TABLE_NAME);
					if ( it != table_queries_.end() )
					{
						Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, CONNECTION_STRING);
						int unique(0);
						std::string unique_query = (*it).second->unique();
						std::cout << unique_query << std::endl;
						tmp << unique_query, into(unique), now;

						data.setIndex(++unique);
						std::string insert_query = (*it).second->insertComplex();

						std::cout << insert_query << std::endl;
						Poco::Data::Statement stmt((tmp << insert_query, use(data), now));

						Poco::Data::Statement::Result result = stmt.executeAsync();

						result.wait();

						return true;
					}				

					return false;
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}

			template <typename DataType, typename TableType>
			bool write(std::vector<DataType>& data)
			{
				return true;
			}
			template <typename DataType, typename TableType>
			bool read(std::vector<DataType>& data, std::string query)
			{
				try
				{
					auto it = table_queries_.find(TableType::TABLE_NAME);
					if (it != table_queries_.end())
					{
						Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, CONNECTION_STRING);
					

						std::string qselect = (*it).second->select();

						std::cout << qselect << std::endl;
						Poco::Data::Statement stmt((tmp << qselect, into(data), now));

						Poco::Data::Statement::Result result = stmt.executeAsync();

						result.wait();

						return true;
					}

					return false;
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				return false;
			}
						
		private:
			static std::string CONNECTION_STRING;
			static bool initilalized;

			static void initilalize()
			{
				if (!initilalized)
				{					
					Poco::SharedPtr<BioPersonTable>    pp  = new BioPersonTable();
					Poco::SharedPtr<BioLocationTable>  lt  = new BioLocationTable();
					Poco::SharedPtr<BioPhotoItemTable> pit = new BioPhotoItemTable();
					Poco::SharedPtr<BioVisitorTable>   vt  = new BioVisitorTable();


				
					std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> person_pair    (BioPersonTable::TABLE_NAME   , pp);
					std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> location_pair  (BioLocationTable::TABLE_NAME , lt);
					std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> photo_item_pair(BioPhotoItemTable::TABLE_NAME, pit);
					std::pair<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> visitor_pair   (BioVisitorTable::TABLE_NAME  , vt);


					table_queries_.insert(person_pair    );
					table_queries_.insert(location_pair  );
					table_queries_.insert(photo_item_pair);
					table_queries_.insert(visitor_pair   );



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

			static std::map<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> table_queries_;
			
		};
	}
}

#endif