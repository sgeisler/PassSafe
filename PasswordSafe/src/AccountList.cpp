#include "AccountList.hpp"
#include <QIODevice>

using namespace bb::data;
using namespace bb::system;

void AccountList::clearClip()
{
	bb::system::Clipboard clipboard;
	clipboard.clear();

	SystemToast *toast = new SystemToast(this);

	toast->setBody("clipboard cleared");
	toast->setPosition(SystemUiPosition::MiddleCenter);
	//toast->setModality(bb::system::SystemUiModality::Global); //this actually doesn't works
	toast->show();
}

AccountList::AccountList()
{
	this->password = "";
	this->file = "./data/accounts.json";



	this->loadAccounts();

}

QString AccountList::getAccountAt(int i)
{
	return this->accounts.at(i).name;
}

int AccountList::getStartAt(int i)
{
	return this->accounts.at(i).start;
}

int AccountList::getStopAt(int i)
{
	return this->accounts.at(i).stop;
}

int AccountList::getSize()
{
	return this->accounts.size();
}

void AccountList::setPassword(QString pass)
{
	this->password = pass;
}

void AccountList::loadAccounts()
{
	this->accounts = QList<Account>();
	JsonDataAccess jda;
	QVariantList list = jda.load(this->file).value<QVariantList>();
	bool* ok = new bool;
	for(int i = 0; i < list.size(); i++)
	{
		accounts.append(Account(list.at(i).toMap().value("name").toString(), list.at(i).toMap().value("start").toInt(ok), list.at(i).toMap().value("stop").toInt(ok)));
	}
	delete(ok);

}

QString AccountList::getPasswordAt(int i, int start = -1, int stop = -1)
{
	QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
	QString accString = this->accounts.at(i).name + this->password;
	hash->addData(accString.toUtf8());
	QString pass = hash->result().toBase64();
	if(start == -1)
	{
		start = accounts.at(i).start;
	}
	if(stop == -1)
	{
		stop = accounts.at(i).stop;
	}

	if(stop < 28)
	{
		pass.remove(stop, pass.length() - 1);
	}
	if(start > 1)
	{
		pass.remove(0, start - 2);
	}


	return pass;
}

QString AccountList::getPasswordAt(int i)
{
	return getPasswordAt(i, -1, -1);
}

void AccountList::addAccount(QString name, int start, int stop)
{
	JsonDataAccess jda;
	QVariantList list = jda.load(this->file).value<QVariantList>();
	QVariantMap acc;
	acc["name"] = QVariant(name);
	acc["start"] = QVariant(start);
	acc["stop"] = QVariant(stop);
	list.append(QVariant(acc));

	jda.save(QVariant(list), this->file);
	loadAccounts();
}

void AccountList::editAccount(int i, QString name, int start, int stop)
{
	JsonDataAccess jda;
	QVariantList list = jda.load(this->file).value<QVariantList>();
	QVariantMap acc;
	acc["name"] = QVariant(name);
	acc["start"] = QVariant(start);
	acc["stop"] = QVariant(stop);
	list.removeAt(i);
	list.insert(i, QVariant(acc));
	jda.save(QVariant(list), this->file);
	loadAccounts();
}

void AccountList::removeAccountAt(int i)
{
	JsonDataAccess jda;
	QVariantList list = jda.load(this->file).value<QVariantList>();
	list.removeAt(i);
	jda.save(QVariant(list), this->file);
	loadAccounts();
}

void AccountList::copyToClipboard(QString str)
{
	bb::system::Clipboard clipboard;
	clipboard.clear();
	clipboard.insert("text/plain", str.toAscii());
	QTimer::singleShot(30000, this, SLOT(clearClip()));

	SystemToast *toast = new SystemToast(this);

	toast->setBody("password copied to clipboard\n(will be deleted in 30 seconds)");
	toast->setPosition(SystemUiPosition::MiddleCenter);
	toast->show();
}

