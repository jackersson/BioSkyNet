#ifndef Bio_Location_Table_INCLUDED
#define Bio_Location_Table_INCLUDED

#include <string>
#include <vector>
#include "Poco/String.h"
#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioLocationTable : public Interfaces::ITableQuery
		{
		public:
			BioLocationTable()
			{
				initialized_ = false;
				createColumns();
			}

			~BioLocationTable()	{	}

			const std::string& tableName()
			{
				return TABLE_NAME;
			}

			static const std::string TABLE_NAME;

			std::string createTable()
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

		private:

			void createColumns()
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


		};
	}
}

#endif
