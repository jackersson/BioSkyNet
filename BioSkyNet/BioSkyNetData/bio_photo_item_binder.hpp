#ifndef Bio_PhotoItem_Binder_INCLUDED
#define Bio_PhotoItem_Binder_INCLUDED

#include "bio_photo_item.hpp"

namespace Poco
{
	namespace Data
	{
		typedef SmartBio::Data::BioPhotoItem PhotoItemType;
		template < >
		class Poco::Data::TypeHandler<PhotoItemType>
		{
		public:
			static void bind(std::size_t pos, const PhotoItemType& obj
				, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir);


			static void prepare(std::size_t pos, const PhotoItemType& obj
				, AbstractPreparator::Ptr pPrepare);


			static std::size_t size();


			static void extract(std::size_t pos, PhotoItemType& obj
				, const PhotoItemType& defVal, AbstractExtractor::Ptr pExt);


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

