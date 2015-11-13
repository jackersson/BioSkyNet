#ifndef Bio_Face_Page_INCLUDED
#define Bio_Face_Page_INCLUDED

#include "iui_subscrible.hpp"

#include "../BioSkyNetData/bio_photo_item_binder.hpp"

#include "wx_bio_face_streamer.hpp"

namespace SmartBio
{
	namespace View
	{

		class MyListModel : public wxDataViewVirtualListModel
		{
		public:
			enum
			{
				/*Col_EditableText,*/
				Col_IconText,
		/*		Col_TextWithAttr,
				Col_Custom,*/
				Col_Max
			};

			MyListModel();

			// helper methods to change the model

			void Prepend(const wxString &text);
			void DeleteItem(const wxDataViewItem &item);
			void DeleteItems(const wxDataViewItemArray &items);
			void AddMany();


			// implementation of base class virtuals to define model

			virtual unsigned int GetColumnCount() const
			{
				return Col_Max;
			}

			virtual wxString GetColumnType(unsigned int col) const
			{
				if (col == Col_IconText)
					return wxT("bitmap");
					//return wxT("wxDataViewIconText");

				return wxT("string");
			}

			virtual void GetValueByRow(wxVariant &variant,
				unsigned int row, unsigned int col) const;
			virtual bool GetAttrByRow(unsigned int row, unsigned int col,
				wxDataViewItemAttr &attr) const;
			virtual bool SetValueByRow(const wxVariant &variant,
				unsigned int row, unsigned int col);

		private:
			wxArrayString    m_textColValues;
			wxArrayString    m_iconColValues;
			wxIcon           m_icon[2];
		};

		class MyCustomRenderer : public wxDataViewCustomRenderer
		{
		public:
			MyCustomRenderer()
				: wxDataViewCustomRenderer("string",
				wxDATAVIEW_CELL_ACTIVATABLE,
				wxALIGN_CENTER)
			{ }

			virtual bool Render(wxRect rect, wxDC *dc, int state)
			{
				dc->SetBrush(*wxLIGHT_GREY_BRUSH);
				dc->SetPen(*wxTRANSPARENT_PEN);

				rect.Deflate(2);
				dc->DrawRoundedRectangle(rect, 5);

				RenderText(m_value,
					0, // no offset
					wxRect(dc->GetTextExtent(m_value)).CentreIn(rect),
					dc,
					state);
				return true;
			}

			virtual bool ActivateCell(const wxRect& WXUNUSED(cell),
				wxDataViewModel *WXUNUSED(model),
				const wxDataViewItem &WXUNUSED(item),
				unsigned int WXUNUSED(col),
				const wxMouseEvent *mouseEvent)
			{
				wxString position;
				if (mouseEvent)
					position = wxString::Format("via mouse at %d, %d", mouseEvent->m_x, mouseEvent->m_y);
				else
					position = "from keyboard";
				wxLogMessage("MyCustomRenderer ActivateCell() %s", position);
				return false;
			}

			virtual wxSize GetSize() const
			{
				return wxSize(60, 20);
			}

			virtual bool SetValue(const wxVariant &value)
			{
				m_value = value.GetString();
				return true;
			}

			virtual bool GetValue(wxVariant &WXUNUSED(value)) const { return true; }

		private:
			wxString m_value;
		};


		class BioFacePage : public wxPanel, public IUiSubscrible
		{
		public:
			BioFacePage(wxWindow* parent, wxWindowID id);
			virtual ~BioFacePage();

			void update(const Data::BioPhotoItem& photo_item);
							
		private:
			void do_create     ();
			void do_unsubscribe();
			void do_subscribe  ();

		private:
			
			void onEnrollFromCamera  (wxCommandEvent& e);
			void onEnrollFromImage   (wxCommandEvent& e);
			void onSelectedFaceDelete(wxCommandEvent& e);
			void onItemSelection     (wxDataViewEvent& e);

		private:
			wxBioFaceStreamer*  person_photo_          ;
			wxDataViewCtrl*     enrolled_photos_holder_;
			wxStaticBitmap*     enroll_status_image_   ;


			//TODO make corresponding type of properties
			wxStringProperty* number_of_faces_    ; //int
			wxStringProperty*	natural_skin_color_ ; //bool
			wxStringProperty*	gender_							; //Gender
			wxStringProperty*	age_								; //int
			wxStringProperty*	glasses_						; //bool
			wxStringProperty*	resolution_					; //string
			wxStringProperty*	ethnicity_					; //Ethnithity
			//Add propery Sample Quality (float)

			wxBitmapButton* btn_enroll_from_camera_;
			wxBitmapButton* btn_enroll_from_image_ ;
			wxBitmapButton* btn_face_delete_       ;

			wxDataViewColumn* first_name_;
			wxDataViewColumn* photo_path_;

			std::map<int, Data::BioPhotoItem> photo_items_;

		};
	}
}

#endif

