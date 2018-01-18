#include "atm_graphics.h"
#include "ui_atm_graphics.h"

ATM_Graphics::ATM_Graphics(ATM& atm, QWidget *parent) :
    QMainWindow(parent),
    _atm(atm),
    ui(new Ui::ATM_Graphics)
{
    ui->setupUi(this);
    connect(ui->pushButton_num0,SIGNAL(released()),this,SLOT(Press_0()));
    connect(ui->pushButton_num1,SIGNAL(released()),this,SLOT(Press_1()));
    connect(ui->pushButton_num2,SIGNAL(released()),this,SLOT(Press_2()));
    connect(ui->pushButton_num3,SIGNAL(released()),this,SLOT(Press_3()));
    connect(ui->pushButton_num4,SIGNAL(released()),this,SLOT(Press_4()));
    connect(ui->pushButton_num5,SIGNAL(released()),this,SLOT(Press_5()));
    connect(ui->pushButton_num6,SIGNAL(released()),this,SLOT(Press_6()));
    connect(ui->pushButton_num7,SIGNAL(released()),this,SLOT(Press_7()));
    connect(ui->pushButton_num8,SIGNAL(released()),this,SLOT(Press_8()));
    connect(ui->pushButton_num9,SIGNAL(released()),this,SLOT(Press_9()));
    connect(ui->pushButton_ok,SIGNAL(released()),this,SLOT(Press_K()));
    connect(ui->pushButton_X,SIGNAL(released()),this,SLOT(Press_X()));
    Card_Scr();
    show();
}

ATM_Graphics::~ATM_Graphics()
{
    delete ui;
}

void ATM_Graphics::Card_Scr()
{
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);

    ui->label->setText("\nEnter your card");
    ui->lineEdit->setPlaceholderText("Card");
    ui->lineEdit->setEnabled(true);
    connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(getCard()));
}

void ATM_Graphics::getCard()
{
    QString card("");
    card = ui->lineEdit->text();
    if(card.length()!=4)
    {
        ui->label->setText("Card must have 4 symbols\nEnter your card");
        return;
    }
    bool b=false;
    unsigned int i = card.toInt(&b,10);
    if(!b)
    {
        ui->label->setText("Card number can have only numbers\nEnter your card");
        return;
    }
    ATM_st* st = _atm.read_Card(i);
    if(*st == "Err_Card")
    {
        ui->label->setText("Card number is not registred or locked\nEnter your card");
        return;
    }
    if(*st == "Lock_Card")
    {
        ui->label->setText("Account is blocked\nEnter your card");
        return;
    }
    else
    {
        _atm.cur().card()=i;
        ui->label->setText("\nEnter pin");
        ui->lineEdit->setText("");
        ui->lineEdit->setPlaceholderText("Pin");
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        disconnect(ui->pushButton_Enter,0,0,0);
        connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT(getCard()));
        connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(getPin()));
    }
    return;
}

void ATM_Graphics::getPin()
{
    QString pin("");
    pin = ui->lineEdit->text();
    if(pin.length()!=4)
    {
        ui->label->setText("Pin must have 4 symbols\nEnter Pin\n\n\n\nEnter another card");
        return;
    }
    bool b=false;
    unsigned int i = pin.toInt(&b,10);
    ui->label->setText(QString(b));
    if(!b)
    {
        ui->label->setText("Pin number can have only numbers\nEnter Pin\n\n\n\nEnter another card");
        return;
    }
    ATM_st* st = _atm.checkPin(i);
    if(*st == "Err_Pin")
    {
        ui->lineEdit->setText("");
        ui->label->setText("Incorrect Pin!\nEnter Pin\n\n\n\nEnter another card");
        return;
    }
    if(*st == "Lock_Card")
    {
        ui->lineEdit->setText("");
        ui->label->setText("Pin failed three times\nAccount is blocked\nEnter Pin\n\n\nEnter another card");
        ui->lineEdit->setPlaceholderText("Card");
        disconnect(ui->pushButton_Enter,0,0,0);
        disconnect(ui->pushButton_help2,0,0,0);
        connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(getCard()));
        return;
    }
    else
    {
        Main_Scr();
        return;
    }
}

void ATM_Graphics::view_balance()
{
    QString s = "Your balance is:\n";
    s.append(_atm.view_balance()->getSt());
    s.append(_atm.cur().view_type());
    s.append("\n\n\n\nBack to Main Menu");
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT (Main_Scr()));
    ui->label->setText(s);
}

void ATM_Graphics::Main_Scr()
{
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
    ui->lineEdit->setText("");
    ui->lineEdit->setEnabled(false);
    disconnect(ui->pushButton_Enter,0,0,0);
    connect(ui->pushButton_help1,SIGNAL(released()),this,SLOT (view_balance()));
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT (withdraw_Scr()));
    connect(ui->pushButton_help3,SIGNAL(released()),this,SLOT (Transfer_Scr()));
    connect(ui->pushButton_help4,SIGNAL(released()),this,SLOT (Replenish_Scr()));
    connect(ui->pushButton_help5,SIGNAL(released()),this,SLOT (Change_Scr()));
    connect(ui->pushButton_help6,SIGNAL(released()),this,SLOT (Card_Scr()));
    ui->label->setText("\nCheck balance                                                          Replenish card\n\n\n\nWithdraw                                                               Change Money\n\n\n\n Transfer                                                                      End session");
    return;
}

void ATM_Graphics::Change_Scr()
{
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);
    QString s = "\nEnter currency you want to change to:\n";
    if(_atm.cur().view_type()=="grn") s.append("grn/dolars:26.450\ngrn/euro:31.189");
    if(_atm.cur().view_type()=="euro") s.append("euro/grn:0.032\neuro/dolars:0.848");
    if(_atm.cur().view_type()=="dolars") s.append("dolars/grn:0.037\ndolars/euro:1.179");
    s.append("\n\nBack to Menu");
    ui->label->setText(s);
    ui->lineEdit->setPlaceholderText("euro/dolars/grn");
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setMaxLength(6);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT(Main_Scr()));
    connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(do_change()));
}

void ATM_Graphics::do_change()
{
    QString cur = ui->lineEdit->text();
    if(cur == _atm.cur().view_type()){
        QString s = "\nYou are already in this currency. Try again:\n";
        if(_atm.cur().view_type()=="grn") s.append("grn/dolars:26.450\ngrn/euro:31.189");
        if(_atm.cur().view_type()=="euro") s.append("euro/grn:0.032\neuro/dolars:0.848");
        if(_atm.cur().view_type()=="dolars") s.append("dolars/grn:0.037\ndolars/euro:1.179");
        s.append("\n\nBack to Menu");
        ui->label->setText(s);
        return;
    }
    if(cur == "grn" || cur == "euro" || cur == "dolars"){
        _atm.changeMoney(cur);
        ui->lineEdit->setText("");
        ui->lineEdit->setEnabled(false);
        ui->lineEdit->setMaxLength(4);
        disconnect(ui->pushButton_Enter,0,0,0);
        ui->label->setText("\nChanging succesfull\n\n\n\nBack to menu");
        return;
    }
    QString s = "\nInvalid type of currency. Try again:\n";
    if(_atm.cur().view_type()=="grn") s.append("grn/dolars:26.450\ngrn/euro:31.189");
    if(_atm.cur().view_type()=="euro") s.append("euro/grn:0.032\neuro/dolars:0.848");
    if(_atm.cur().view_type()=="dolars") s.append("dolars/grn:0.037\ndolars/euro:1.179");
    s.append("\n\nBack to Menu");
    ui->label->setText(s);
    return;
}

void ATM_Graphics::Replenish_Scr()
{
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT(Main_Scr()));
    ui->lineEdit->setMaxLength(12);
    ui->label->setText("\nEnter amount\n\n\n\nBack to Menu");
    ui->lineEdit->setPlaceholderText("Amount");
    ui->lineEdit->setEnabled(true);
    connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(do_replenish()));
}

void ATM_Graphics::do_replenish()
{
    bool b=false;
    unsigned int i = ui->lineEdit->text().toInt(&b,10);
    if(!b)
    {
        ui->label->setText("Enter amount\nInput error. Try again\n\n\n\nBack to Menu");
        return;
    }
    if(ui->lineEdit->text().contains('-'))
    {
        ui->label->setText("Enter amount\nAmount to replenish cant be less, than zero!\n\n\n\nBack to Menu");
        return;
    }
    _atm.replenish(i);
    ui->lineEdit->setText("");
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setMaxLength(4);
    disconnect(ui->pushButton_Enter,0,0,0);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT (Main_Scr()));
    ui->label->setText("\nReplenish succesfull\n\n\n\nBack to menu");

    return;
}

void ATM_Graphics::withdraw_Scr()
{
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT(Main_Scr()));
    ui->lineEdit->setMaxLength(12);
    QString s = "Enter sum you want to withdraw\nAvailable nominals:\n\n\n\nBack to Menu";
    QMapIterator<size_t,size_t> i(_atm.moneyGrn().map());
    QString trys="euro";
    if(_atm.cur().view_type()==trys){
        QMapIterator<size_t,size_t> m(_atm.moneyEuro().map());
        i=m;
    }
    trys="dolars";
    if(_atm.cur().view_type()==trys){
     QMapIterator<size_t,size_t> m(_atm.moneyDolars().map());
    i=m;
    }

    while(i.hasNext())
    {
        i.next();
        s.append(QString::number(i.key()));
        s.append("(");
        s.append(QString::number(i.value()));
        s.append(");");
    }
    ui->label->setText(s);
    ui->lineEdit->setPlaceholderText("Summ");
    ui->lineEdit->setEnabled(true);
    connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(do_withdraw()));
}

void ATM_Graphics::do_withdraw()
{
    bool b=false;
    unsigned int i = ui->lineEdit->text().toInt(&b,10);
    if(!b)
    {
        ui->label->setText("Enter sum you want to withdraw\nInput error. Try again\n\n\n\nBack to Menu");
        return;
    }
    if(i<=0)
    {
        ui->label->setText("Enter sum you want to withdraw\nSumm to withdraw cant be less, than zero!\n\n\n\nBack to Menu");
        return;
    }
    ATM_st* st = _atm.withdraw(i);
    if(*st == "Err_Costs_Card")
    {
        ui->label->setText("Enter sum you want to withdraw\nNot enough costs on account!\n\n\n\nBack to Menu");
        return;
    }
    if(*st == "Err_Costs_Atm")
    {
        ui->label->setText("Enter sum you want to withdraw\nAtm cannot give you this amount\n\n\n\nBack to Menu");
        return;
    }
    if(*st == "Err_Type")
    {
        ui->label->setText("You have different type\n\n\n\nBack to Menu");
        return;
    }
    else
    {
        ui->lineEdit->setText("");
        ui->lineEdit->setEnabled(false);
        ui->lineEdit->setMaxLength(4);
        disconnect(ui->pushButton_Enter,0,0,0);
        connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT (Main_Scr()));
        ui->label->setText("\nWithdraw succesfull\n\n\n\nBack to menu");

        return;
    }
}

void ATM_Graphics::Transfer_Scr()
{
    disconnect(ui->pushButton_help1,0,0,0);
    disconnect(ui->pushButton_help2,0,0,0);
    disconnect(ui->pushButton_help3,0,0,0);
    disconnect(ui->pushButton_help4,0,0,0);
    disconnect(ui->pushButton_help5,0,0,0);
    disconnect(ui->pushButton_help6,0,0,0);
    connect(ui->pushButton_help2,SIGNAL(released()),this,SLOT(Main_Scr()));
    QString s = "\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu";
    ui->label->setText(s);
    ui->lineEdit->setPlaceholderText("Card Number");
    ui->lineEdit->setEnabled(true);
    connect(ui->pushButton_Enter,SIGNAL(released()),this,SLOT(do_transfer_card()));
}

void ATM_Graphics::do_transfer_card()
{
    QString card("");
    card = ui->lineEdit->text();
    if(card.length()!=4)
    {
        ui->label->setText("Card must have 4 symbols\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    bool b=false;
    unsigned int i = card.toInt(&b,10);
    if(!b)
    {
        ui->label->setText("Card number can have only numbers\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    if(i==_atm.cur().card())
    {
        ui->label->setText("You can't transfer to yourself\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    if((ui->lineEdit->text().contains('-')))
    {
        ui->label->setText("You can't transfer less than zero!\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    ATM_st* st = _atm.read_Card(i);
    if(*st == "Err_Card")
    {
        ui->label->setText("Card number is not registred\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    if(*st == "Lock_Card")
    {
        ui->label->setText("Account is blocked\nEnter number of card where you want to transfer to\n\n\n\nBack to Menu");
        return;
    }
    if(*st == "Err_Type")
    {
        ui->label->setText("You have different type\n\n\n\nBack to Menu");
        return;
    }
    ui->label->setText("\nEnter amount you want to transfer\n\n\n\nBack to menu");
    ui->lineEdit->setPlaceholderText("Amount");
    ui->lineEdit->setText("");
    disconnect(ui->pushButton_Enter,0,0,0);
    ui->lineEdit->setMaxLength(12);
    QSignalMapper* signalMapper = new QSignalMapper (this);
    signalMapper -> setMapping (ui->pushButton_Enter,i);
    connect (ui->pushButton_Enter, SIGNAL(released()), signalMapper, SLOT(map()));
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(do_transfer_amount(int))) ;
}

void ATM_Graphics::do_transfer_amount(int card)
{
    QString amount("");
    amount = ui->lineEdit->text();
    bool b=false;
    double i = amount.toDouble(&b);
    if(!b)
    {
        ui->label->setText("Amount can have only numbers\nEnter amount you want to transfer\n\n\n\nBack to Menu");
        return;
    }
    ATM_st* st = _atm.transfer(card,i);
    if(*st == "Err_Costs_Card")
    {
        ui->label->setText("Not enough costs on account!\nEnter amount you want to transfer\n\n\n\nBack to Menu");
        return;
    }
    if(*st == "Err_Type")
    {
        ui->label->setText("You have different type\n\n\n\nBack to Menu");
        return;
    }
    ui->lineEdit->setText("");
    ui->lineEdit->setEnabled(false);
    disconnect(ui->pushButton_Enter,0,0,0);
    ui->lineEdit->setMaxLength(4);
    ui->label->setText("\nTransfer succesfull!\n\n\n\nBack to Menu");

    return;
}



void ATM_Graphics::Press_0()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'0');}

void ATM_Graphics::Press_1()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'1');}

void ATM_Graphics::Press_2()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'2');}

void ATM_Graphics::Press_3()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'3');}

void ATM_Graphics::Press_4()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'4');}

void ATM_Graphics::Press_5()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'5');}

void ATM_Graphics::Press_6()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'6');}

void ATM_Graphics::Press_7()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'7');}

void ATM_Graphics::Press_8()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'8');}

void ATM_Graphics::Press_9()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText(ui->lineEdit->text()+'9');}

void ATM_Graphics::Press_K()
{if(ui->lineEdit->isEnabled())ui->pushButton_Enter->click();}

void ATM_Graphics::Press_X()
{if(ui->lineEdit->isEnabled())ui->lineEdit->setText("");}
