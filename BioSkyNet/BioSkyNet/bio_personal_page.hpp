#ifndef Bio_Personal_Page_INCLUDED
#define Bio_Personal_Page_INCLUDED

#include "iui_subscrible.hpp"
#include "../BioSkyNetData/bio_person_binder.hpp"
#include "bio_properties.hpp"
#include "wx_bio_face_streamer.hpp"


namespace SmartBio
{
	namespace View
	{

		class BioPersonalPage : public wxPanel, public IUiSubscrible
		{
		public:
			
			BioPersonalPage(wxWindow* parent, wxWindowID id);

			virtual ~BioPersonalPage();
			void update(const  Data::BioPerson& person);
			void update(bool default_update = true);

			Data::BioPerson& getEditablePerson();

		private:
			void onBtnRefreshClick       (wxCommandEvent& e);
			void onBtnFileOpenClick      (wxCommandEvent& e);
			void onBtnSaveClick          (wxCommandEvent& e);
			void onBtnDeleteClick        (wxCommandEvent& e);		
			void onPropertyValueChanging (wxCommandEvent& e);

			void addUserToDataBase   ();
			bool checkValidProperties(); 

		private:
			wxBioFaceStreamer* avatar_            ;
			wxPropertyGrid*    person_information_;
			wxBitmapButton*    btn_add_user_      ;
			wxBitmapButton*    btn_refresh_       ;
			wxBitmapButton*    btn_open_          ;
			wxBitmapButton*    btn_save_          ;
			wxBitmapButton*    btn_delete_        ;

			wxTextPropertyEx*   first_name_   ;
			wxTextPropertyEx*   last_name_    ;
			wxTextPropertyEx*   country_      ;
			wxTextPropertyEx*	  city_         ;
			wxStringProperty*	  comments_	    ;
			wxEmailPropertyEx*	email_        ;
			wxDateProperty*     date_of_birth_;
			wxEnumProperty*     gender_       ;
			wxEnumProperty*     rights_       ;

		private:
			wxInfoBar*     info_bar;	

			Data::BioPerson person_;
			Data::BioPerson editable_person_;			

			//holding all properties to check are they valid or not
			std::map<std::string, int> properties_;

		private:
			void do_create();
			void do_unsubscribe();
			void do_subscribe();
			

			
		};		
	}
}

#endif

