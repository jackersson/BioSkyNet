#ifndef Bio_View_Zoom_Slider_Included
#define Bio_View_Zoom_Slider_Included

#include <wx/window.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include "wx_bio_view.hpp"

namespace SmartBio {
	namespace View
	{

		class wxBioViewZoomSlider : public wxWindow
		{
		public:
			explicit wxBioViewZoomSlider( wxWindow * parent = NULL, int id = wxID_ANY
				                        , const wxPoint & position = wxDefaultPosition
				                        , const wxSize & size = wxDefaultSize)
				                        : wxWindow(parent, id, position, size)
			{				
				create();
			}

			virtual ~wxBioViewZoomSlider()
			{
				
			}

			void setBioView( Poco::SharedPtr<wxBioView> bio_view )
			{
				if (bio_view != bio_view_)
				{
					if ( !bio_view_ .isNull() )
					{
						bio_view_->Unbind(wxEVT_N_VIEW_ZOOM_CHANGED, &wxBioViewZoomSlider::onViewZoomChanged, this);
						bio_view_->Unbind(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, &wxBioViewZoomSlider::onViewZoomToFitChanged, this);
					}

					bio_view_ = bio_view;

					if (!bio_view_.isNull())
					{
						bio_view_->Bind(wxEVT_N_VIEW_ZOOM_CHANGED, &wxBioViewZoomSlider::onViewZoomChanged, this);
						bio_view_->Bind(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, &wxBioViewZoomSlider::onViewZoomToFitChanged, this);
					}
					updateValues();
				}
			}

			Poco::SharedPtr<wxBioView> GetView()
			{
				return bio_view_;
			}

		private:
			void create()
			{
				wxFlexGridSizer* main_flex_sizer;
				main_flex_sizer = new wxFlexGridSizer(0, 4, 0, 0);
				main_flex_sizer->AddGrowableCol(1);
				main_flex_sizer->SetFlexibleDirection(wxBOTH);
				main_flex_sizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

				checkbox_zoom_to_fit_ = new wxCheckBox( this, wxID_ANY, wxT("Zoom to fit")
					                                    , wxDefaultPosition, wxDefaultSize, 0);
				main_flex_sizer->Add(checkbox_zoom_to_fit_, 0, wxALL, 5);

				slider_ = new wxSlider( this, wxID_ANY, 100, 10, 200, wxDefaultPosition
					                    , wxDefaultSize, wxSL_HORIZONTAL);
				main_flex_sizer->Add(slider_, 0, wxALL | wxEXPAND, 5);

				spin_control_ = new wxSpinCtrl( this, wxID_ANY, wxEmptyString
					                            , wxDefaultPosition, wxDefaultSize
																			, wxSP_ARROW_KEYS, 10, 200, 100);
				spin_control_->SetMaxSize(wxSize(55, -1));

				main_flex_sizer->Add(spin_control_, 0, wxALL, 5);

				wxStaticText * static_text_percents_ = new wxStaticText(this, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0);
				static_text_percents_->Wrap(-1);
				main_flex_sizer->Add(static_text_percents_, 0, wxALL, 5);

				this->SetSizer(main_flex_sizer);
				this->Layout();
			}

			void onViewZoomChanged(wxCommandEvent& /*event*/)
			{
				updateValues();
			}

			void onViewZoomToFitChanged(wxCommandEvent& /*event*/)
			{
				updateValues();
			}

			void onSliderValueChanged(wxCommandEvent& /*event*/)
			{
				if (!bio_view_ .isNull())				
					bio_view_->setZoom(slider_->GetValue() / 100.0);				
			}

			void onSpinValueChanged(wxSpinEvent& /*event*/)
			{
				if (!bio_view_.isNull())				
					bio_view_->setZoom(spin_control_->GetValue() / 100.0);				
			}

			void onChbZoomToFitChanged(wxCommandEvent& /*event*/)
			{
				if (!bio_view_.isNull())				
					bio_view_->setZoomToFit(checkbox_zoom_to_fit_->GetValue());				
			}

			void updateValues()
			{
				if (!bio_view_.isNull())
				{
					int value = (int)(bio_view_->getZoom() * 100);

					int max = slider_->GetMax();
					int min = slider_->GetMin();

					bool zoom_to_fit = bio_view_->getZoomToFit();

					if (value < min)
						value = min;
					if (value > max) 
						value = max;

					slider_->SetValue(value);
					spin_control_->SetValue(value);
					checkbox_zoom_to_fit_->SetValue(bio_view_->getZoomToFit());

					slider_->Enable(!zoom_to_fit);
					spin_control_->Enable(!zoom_to_fit);
				}
			}

		private:
			Poco::SharedPtr<wxBioView> bio_view_;

			wxCheckBox*  checkbox_zoom_to_fit_;
			wxSlider*    slider_              ;
			wxSpinCtrl*  spin_control_        ;

		private:
			DECLARE_EVENT_TABLE();
		};

	}
};

#endif
