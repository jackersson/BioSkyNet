#include "stdafx.h"
#include "bio_photo_item_table.hpp"

#include "Poco/String.h"

namespace SmartBio
{
	namespace Data
	{
		const std::string BioPhotoItemTable::TABLE_NAME = " bio_photo_items ";

		BioPhotoItemTable::BioPhotoItemTable()
		{
			initialized_ = false;
			createColumns();
		}

		const std::string& BioPhotoItemTable::tableName()
		{
			return TABLE_NAME;
		}
		
		std::string BioPhotoItemTable::createTable()
		{						
			std::vector<std::string> query;
			query.push_back(formatColumn(0, typeBigInteger(), " ", typePrimaryKey()));
			query.push_back(formatColumn(1, typeNText()      , typeNotNull()));
			query.push_back(formatColumn(2, typeNText()      , typeNotNull()));
			query.push_back(formatColumn(3, typeTinyInteger(), typeNotNull()));
			query.push_back(formatColumn(4, typeInteger()    , typeNotNull()));
			query.push_back(formatColumn(5, typeTinyInteger(), typeNotNull()));
			query.push_back(formatColumn(6, typeTinyInteger(), typeNotNull()));
			query.push_back(formatColumn(7, typeNText()      , typeNotNull()));
			query.push_back(formatColumn(8, typeInteger()    , typeNotNull()));
			query.push_back(formatColumn(9, typeFloat()      , typeNotNull()));

			std::string create_table_cols = Poco::cat(std::string(", "), query.begin(), query.end());

			std::string result = create(create_table_cols);

			return result;
		}

		void BioPhotoItemTable::createColumns()
		{
			if (!initialized_)
			{
				columns_.push_back("Id"              );
				columns_.push_back("PhotoPath"       );
				columns_.push_back("FirPath"         );
				columns_.push_back("NaturalSkinColor");
				columns_.push_back("Gender"          );
				columns_.push_back("Age"             );
				columns_.push_back("Glasses"         );
				columns_.push_back("Resolution"      );
				columns_.push_back("Etnicity"        );
				columns_.push_back("SampleQuality"   );

				initialized_ = true;
			}
		}
	}
}