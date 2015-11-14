#ifndef Bio_Location_Table_INCLUDED
#define Bio_Location_Table_INCLUDED

#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioDbIO;
		class BioLocation;
		class BioLocationTable : public Interfaces::ITableQuery
		{
		public:
			~BioLocationTable()	{	}

		private:
			friend class BioDbIO;
			friend class BioLocation;

			static const std::string TABLE_NAME;

			BioLocationTable();		
			
			const std::string& tableName    ();
			std::string        createTable  ();
			void               createColumns();
		};
	}
}

#endif
