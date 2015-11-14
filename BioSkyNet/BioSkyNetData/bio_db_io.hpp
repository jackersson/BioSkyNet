#ifndef Bio_DB_IO_INCLUDED
#define Bio_DB_IO_INCLUDED

#include "bio_person_binder.hpp"
#include "bio_location_binder.hpp"
#include "bio_photo_item_binder.hpp"
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
				setConnectionString(connection_string);
				initilalize();
			}
			~BioDbIO(){}

			template <typename DataType>
			bool write(DataType& data)
			{
				std::vector<DataType> dataholder;
				dataholder.push_back(data);
				return write<DataType>(dataholder);			
			}

			template <typename DataType>
			bool write(std::vector<DataType>& data)
			{
				try
				{
					auto it = table_queries_.find(DataType::tableName());
					if (it != table_queries_.end())
					{
						Poco::Data::Session tmp(Poco::Data::SQLite::Connector::KEY, CONNECTION_STRING);
						int unique(0);
						std::string unique_query = (*it).second->unique();
						std::cout << unique_query << std::endl;
						tmp << unique_query, into(unique), now;

						for (auto itr = data.begin(); itr != data.end(); ++itr)
							(*itr).setIndex(++unique);
					
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
				return true;
			}

			template <typename DataType>
			bool read(std::vector<DataType>& data, std::string query)
			{
				try
				{
					auto it = table_queries_.find(DataType::tableName());
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

			void setConnectionString(std::string connection_string);
		
						
		private:
			static std::string CONNECTION_STRING;
			static bool initilalized;

			static void initilalize();	

			static std::map<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> table_queries_;
			
		};
	}
}

#endif