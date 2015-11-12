#ifndef Bio_Visitor_INCLUDED
#define Bio_Visitor_INCLUDED

#include "idatabase_io.hpp"


namespace SmartBio
{
	namespace Data
	{
		enum Status
		{
			Access = 0
			, Deny

		};

		class BioVisitor
		{
		public:
			BioVisitor();

			BioVisitor(int index
				, const std::string&     person_indexs
				, const std::string&     photo_indexs
				, int               	   detected_face_count
				, const std::string&     full_photo_pathway
				, const Poco::DateTime&  detection_time
				, const std::string&     location_indexs
				, Status                 status);

			virtual ~BioVisitor();

			bool operator==(const BioVisitor& other) const
			{
				return    index_ == other.index();


			}

			bool operator < (const BioVisitor& p) const
			{
				if (index_ < p.index())
					return true;
				else
					return false;
			}

			const std::string& operator() () const
			{
				return full_photo_pathway_;
			}


			const std::string&      personIndexs()       const;
			const std::string&      photoIndexs()        const;
			int               	    detectedFaceCount()  const;
			const std::string&      fullPhotoPathway()   const;
			const Poco::DateTime&   detectionTime()      const;
			const std::string&      locationIndexs()     const;
			Status                  status()             const;		
			int                     index()              const;


		public:
			void setPersonIndexs	   (const std::string&    person_indexs      );
			void setPhotoIndexs      (const std::string&    photo_indexs       );			
			void setDetectedFaceCount(int               	  detected_face_count);
			void setFullPhotoPathway (const std::string&    full_photo_pathway );
			void setDetectionTime    (const Poco::DateTime& detection_time     );
			void setLocationIndexs   (const std::string&    location_indexs    );
			void setStatus           (Status                status             );
			void setIndex            (int                   index              );                  




		private:
			std::string    person_indexs_      ;
			std::string    photo_indexs_       ;
			int       	   detected_face_count_;
			std::string    full_photo_pathway_ ;
			Poco::DateTime detection_time_     ;
			std::string    location_indexs_    ;
			Status         status_             ;
			int            index_              ;


		};


	}
}

#endif

