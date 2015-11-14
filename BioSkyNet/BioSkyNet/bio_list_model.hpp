#ifndef Bio_List_Model_INCLUDED
#define Bio_List_Model_INCLUDED

#include "../BioSkyNetData/bio_person_binder.hpp"



namespace SmartBio
{
	namespace View
	{

		class MyListModel : public wxDataViewVirtualListModel
		{
		public:
			enum
			{
				Col_EditableText,
				Col_IconText,
				Col_FirstName,
				Col_LastName,
				Col_DateOfBirth,
				Col_Gender,
				Col_Country,
				Col_City,
				Col_Avatar,
				Col_Photo,
				Col_Email,
				Col_Comments,
				Col_Rights,


				/*		Col_TextWithAttr,
				Col_Custom,*/
				Col_Max
			};

			MyListModel(std::vector<Data::BioPerson>);
			~MyListModel();


			// helper methods to change the model
			std::vector<Data::BioPerson> vec_data;
			void Prepend(const wxString &text);
			void DeleteItem(const wxDataViewItem &item);
			void DeleteItems(const wxDataViewItemArray &items);
			void AddMany();


			// implementation of base class virtuals to define model

			virtual unsigned int GetColumnCount() const;


			virtual wxString GetColumnType(unsigned int col) const;


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
		

	}
}


#endif
