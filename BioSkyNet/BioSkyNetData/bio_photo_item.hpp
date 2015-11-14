#ifndef Bio_PhotoItem_INCLUDED
#define Bio_PhotoItem_INCLUDED

#include "idatabase_io.hpp"
#include "bio_data_types.hpp"

namespace SmartBio
{
	namespace Data
	{
		
		class BioPhotoItem
		{
		public:
			BioPhotoItem();

			BioPhotoItem( int index
				          , const std::string&     photo_path
				          , const std::string&     fir_path
				          , bool               	   natural_skin_color
				          , Gender                 gender
				          , int                    age
				          , bool                   glasses
				          , const std::string&     resolution
				          , Etnicity               etnicity         
									, float                  sample_quality );

			virtual ~BioPhotoItem();

			bool operator==(const BioPhotoItem& other) const
			{
				return    index_ == other.index();
			}

			bool operator < (const BioPhotoItem& p) const
			{
				if (index_ < p.index())
					return true;
				else
					return false;
			}

			const std::string& operator() () const
			{
				return fir_path_;
			}

			const std::string&   photoPath()					 const;
			const std::string&   firPath()						 const;
			bool                 naturalSkinColor()	   const;
			Gender               gender()							 const;
			int                  age()								 const;
			bool                 glasses()						 const;
			const std::string&   resolution()					 const;
			Etnicity             etnicity()            const;
			float                sampleQuality()       const;
			int                  index()               const;

		public:
			void setPhotoPath        (const std::string&     photo_path        );  
			void setFirPath					 (const std::string&     fir_path					 );
			void setNaturalSkinColor (bool               	   natural_skin_color);
			void setGender					 (Gender                 gender						 );
			void setAge							 (int                    age							 );
			void setGlasses					 (bool                   glasses					 );
			void setResolution			 (const std::string&     resolution				 );
			void setEtnicity				 (Etnicity               etnicity          );
			void setSampleQuality    (float                  sample_quality    );
			void setIndex            (int                    index             );

		private:
			std::string        photo_path_         	;
			std::string        fir_path_					 	;
			bool               natural_skin_color_	;
			Gender             gender_						 	;
			int                age_							 		;
			bool               glasses_					 		;
			std::string        resolution_				 	;
			Etnicity           etnicity_          	;
			float              sample_quality_      ;
			int                index_             	;
			

		};


	}
}

#endif

