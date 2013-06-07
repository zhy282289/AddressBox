#ifndef ADDRESSBOXMODEL_H
#define ADDRESSBOXMODEL_H

#include <QAbstractTableModel>


struct AddressBox
{
	QString name;
	QString address;

	bool operator == (const AddressBox &right);
};
Q_DECLARE_METATYPE(AddressBox)
typedef QList<AddressBox> AddressBoxs;



class AddressBoxModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	enum AddressBoxHeader {NAME, ADDRESS};
public:
	explicit AddressBoxModel(AddressBoxs *addressBox, QObject *parent);
	~AddressBoxModel();



	Qt::ItemFlags	flags ( const QModelIndex & index ) const;
	QVariant	data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;
	int	rowCount ( const QModelIndex & parent = QModelIndex() ) const ;
	int	columnCount ( const QModelIndex & parent = QModelIndex() ) const;
	bool	setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
	bool	insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
	bool	removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
	QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

	AddressBoxs* GetAddressBoxs();

private:
	AddressBoxs	*m_addressBoxs;
};

#endif // ADDRESSBOXMODEL_H
