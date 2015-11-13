#ifndef Bio_Person_Table_INCLUDED
#define Bio_Person_Table_INCLUDED

#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioDbIO;
		class BioPerson;
		class BioPersonTable : public Interfaces::ITableQuery
		{
		public:
			~BioPersonTable()	{	}

		private:
			static const std::string TABLE_NAME;

			friend class BioDbIO  ;
			friend class BioPerson;

			BioPersonTable();

			const std::string&      tableName  ();
			std::string             createTable();
			void                    createColumns();			
		};
	}
}

#endif
