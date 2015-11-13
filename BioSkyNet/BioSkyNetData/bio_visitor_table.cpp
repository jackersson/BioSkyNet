#include "stdafx.h"
#include "bio_visitor_table.hpp"

#include "Poco/String.h"

namespace SmartBio
{
	namespace Data
	{
		const std::string BioVisitorTable::TABLE_NAME = " bio_visitors ";

		BioVisitorTable::BioVisitorTable()
		{
			initialized_ = false;
			createColumns();
		}


		const std::string& BioVisitorTable::tableName()
		{
			return TABLE_NAME;
		}
			
		std::string BioVisitorTable::createTable()
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

		void BioVisitorTable::createColumns()
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
	}
}