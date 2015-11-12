#ifndef Bio_Visistors_Binder_INCLUDED
#define Bio_Visistors_Binder_INCLUDED

#include "bio_visitors.hpp"

namespace Poco
{
	namespace Data
	{
		typedef SmartBio::Data::BioVisitor VisitorType;
		template < >
		class Poco::Data::TypeHandler<VisitorType>
		{
		public:
			static void bind(std::size_t pos, const VisitorType& obj
				, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir);


			static void prepare(std::size_t pos, const VisitorType& obj
				, AbstractPreparator::Ptr pPrepare);


			static std::size_t size();


			static void extract(std::size_t pos, VisitorType& obj
				, const VisitorType& defVal, AbstractExtractor::Ptr pExt);


		private:
			static const int DATABASE_COLUMNS_SIZE = 8;

			TypeHandler();
			~TypeHandler();
			TypeHandler(const TypeHandler&);
			TypeHandler& operator=(const TypeHandler&);

		};



	}
}

#endif

