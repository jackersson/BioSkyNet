#ifndef BioPerson_DB_IO_INCLUDED
#define BioPerson_DB_IO_INCLUDED

#include "idatabase_io.hpp"
#include "bio_person_binder.hpp"

namespace SmartBio
{
	namespace Data
	{
		typedef SmartBio::Data::BioPerson PersonType;
		class BioPersonDbIO : public SmartBio::Interfaces::IDatabaseIO<PersonType>
		{
		public:

			BioPersonDbIO(std::string connection_string);
			~BioPersonDbIO();

			
			bool write( BioPerson& data             );
			bool write( std::vector<PersonType>& data);			
		
			bool read (std::vector<BioPerson>& data, std::string query );
		

		public:

			const std::string& bioPersonInsert()
			{
				static  std::string query("INSERT INTO bio_subjects VALUES( :id, :fn, :ln, :db, :gn, :cn, :ct, :cm, :ph )");
				return query;
			}

			const std::string& bioPersonSelect()
			{
				static  std::string query("SELECT * FROM bio_subjects");
				return query;
			}

			static const std::string& bioPersonUnique()
			{
				static  const std::string query("SELECT max(Id) FROM bio_subjects");
				return query;
			}

			static const std::string test;

		private:
			std::string connection_string_;		

			void initialize();

		};
	}
}

#endif