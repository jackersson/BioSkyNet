#ifndef Bio_Visitor_Table_INCLUDED
#define Bio_Visitor_Table_INCLUDED

#include <string>
#include <vector>
#include "Poco/String.h"
#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioVisitorTable : public Interfaces::ITableQuery
		{
		public:
			BioVisitorTable()
			{
				initialized_ = false;
				createColumns();
			}

			~BioVisitorTable()	{	}

			const std::string& tableName()
			{
				return TABLE_NAME;
			}

			static const std::string TABLE_NAME;

			std::string createTable()
			{

				std::vector<std::string> query;
				query.push_back(formatColumn(0, typeBigInteger(), " ", typePrimaryKey()));
				query.push_back(formatColumn(1, typeNText()      , typeNotNull()));
				query.push_back(formatColumn(2, typeNText()      , typeNotNull()));
				query.push_back(formatColumn(3, typeTinyInteger(), typeNotNull()));
				query.push_back(formatColumn(4, typeNText()      , typeNotNull()));
				query.push_back(formatColumn(5, typeDatetime()   , typeNotNull()));
				query.push_back(formatColumn(6, typeNText()      , typeNotNull()));
				query.push_back(formatColumn(7, typeTinyInteger(), typeNotNull()));


				std::string create_table_cols = Poco::cat(std::string(", "), query.begin(), query.end());

				std::string result = create(create_table_cols);

				return result;
			}

		private:

			void createColumns()
			{
				if (!initialized_)
				{
					columns_.push_back("Id"               );
					columns_.push_back("PersonIndexs"     );
					columns_.push_back("PhotoIndexs"      );
					columns_.push_back("DetectedFaceCount");
					columns_.push_back("FullPhotoPathway" );
					columns_.push_back("DetectionTime"    );
					columns_.push_back("LocationIndexs"   );
					columns_.push_back("Status"           );


					initialized_ = true;
				}
			}


		};
	}
}

#endif
