#include "stdafx.h"
#include "bio_location_table.hpp"
#include "Poco/String.h"

namespace SmartBio
{
	namespace Data
	{
		const std::string BioLocationTable::TABLE_NAME = " bio_locations ";

		BioLocationTable::BioLocationTable()
		{
			initialized_ = false;
			createColumns();
		}
			
		const std::string& BioLocationTable::tableName()
		{
			return TABLE_NAME;
		}

		std::string BioLocationTable::createTable()
		{
			std::vector<std::string> query;
			query.push_back(formatColumn(0, typeBigInteger(), " ", typePrimaryKey()));
			query.push_back(formatColumn(1, typeNText()     , typeNotNull()));
			query.push_back(formatColumn(2, typeNText()     , typeNotNull()));
			query.push_back(formatColumn(3, typeNText()     , typeNotNull()));
			query.push_back(formatColumn(4, typeNText()     , typeNotNull()));
			query.push_back(formatColumn(5, typeInteger()   , typeNotNull()));
			query.push_back(formatColumn(6, typeFloat()     , typeNotNull()));
			query.push_back(formatColumn(7, typeFloat()     , typeNotNull()));
			query.push_back(formatColumn(8, typeFloat()     , typeNotNull()));
			query.push_back(formatColumn(9, typeFloat()     , typeNotNull()));		

			std::string create_table_cols = Poco::cat(std::string(", "), query.begin(), query.end());

			std::string result = create(create_table_cols);

			return result;
		}


		void BioLocationTable::createColumns()
		{
			if (!initialized_)
			{
				columns_.push_back("Id"               );
				columns_.push_back("LocationName"     );
				columns_.push_back("PortName"         );
				columns_.push_back("EmailNotification");
				columns_.push_back("CameraName"       );
				columns_.push_back("AgeTresHold"      );
				columns_.push_back("FaceConfidence"   );
				columns_.push_back("MinEyeDistance"   );
				columns_.push_back("MaxEyeDistance"   );
				columns_.push_back("MatchingTreshold" );				
		
				initialized_ = true;
			}
		}
	}
}