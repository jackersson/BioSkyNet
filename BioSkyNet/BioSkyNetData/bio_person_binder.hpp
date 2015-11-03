#ifndef Bio_Person_Binder_INCLUDED
#define Bio_Person_Binder_INCLUDED

#include "bio_person.hpp"

namespace Poco
{
	namespace Data
	{
		typedef SmartBio::Data::BioPerson PersonType;
		template < >
		class Poco::Data::TypeHandler<PersonType>
		{
		public:
			static void bind(std::size_t pos, const PersonType& obj
				, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir);
			

			static void prepare(std::size_t pos, const PersonType& obj
				, AbstractPreparator::Ptr pPrepare);
			
		
			static std::size_t size();
			

			static void extract(std::size_t pos, PersonType& obj
				, const PersonType& defVal, AbstractExtractor::Ptr pExt);
			

		private:
			static const int DATABASE_COLUMNS_SIZE = 9;

			TypeHandler();
			~TypeHandler();
			TypeHandler(const TypeHandler&);
			TypeHandler& operator=(const TypeHandler&);
		
		};


	
	}
}

#endif

