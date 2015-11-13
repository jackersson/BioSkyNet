#include "stdafx.h"
#include "bio_person_table.hpp"

/*
#include <string>
#include <vector>*/
#include "Poco/String.h"

namespace SmartBio
{
	namespace Data
	{
		const std::string BioPersonTable::TABLE_NAME = " bio_subjects ";

		BioPersonTable::BioPersonTable()
		{
			initialized_ = false;
			createColumns();
		}

		const std::string& BioPersonTable::tableName()
		{				
			return TABLE_NAME;
		}		

		std::string BioPersonTable::createTable()
		{				
			std::vector<std::string> query;
			query.push_back(formatColumn(0 , typeInteger(), " ", typePrimaryKey()));
			query.push_back(formatColumn(1 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(2 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(3 , typeDatetime()    , typeNotNull()));
			query.push_back(formatColumn(4 , typeTinyInteger() , typeNotNull()));
			query.push_back(formatColumn(5 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(6 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(7 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(8 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(9 , typeNText()       , typeNotNull()));
			query.push_back(formatColumn(10, typeNText()       , typeNotNull()));
			query.push_back(formatColumn(11, typeTinyInteger() , typeNotNull()));

			std::string create_table_cols = Poco::cat(std::string(", "), query.begin(), query.end());

			std::string result = create(create_table_cols);

			return result;
		}
			
		void BioPersonTable::createColumns()
		{
			if (!initialized_)
			{
				columns_.push_back("Id"            );
				columns_.push_back("FirstName"     );
				columns_.push_back("LastName"      );
				columns_.push_back("DateOfBirth"   );
				columns_.push_back("Gender"        );
				columns_.push_back("Country"       );
				columns_.push_back("City"          );
				columns_.push_back("Avatar"        );
				columns_.push_back("BioPhotoIndexs");
				columns_.push_back("Email"         );
				columns_.push_back("Comment"       );
				columns_.push_back("Rights"        );

				initialized_ = true;
			}
		}
	}
}