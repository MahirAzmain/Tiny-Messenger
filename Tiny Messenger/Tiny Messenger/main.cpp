//
//  main.cpp
//  Tiny Messenger
//
//  Created by Mahir Azmain Haque on 27/5/23.
//

#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void page1();

void page2(string);

map<string,string> user;

class frnd
{
    vector<string> flist;
    struct chat
    {
    int message_id;
    string sender,receiver;
    char mess[50][100];
    int num_of_message=0;
    };

public:
    map<string,chat> sms;
    void addfriend(string);
    void unfriend(string);
    void dispfriend(string);
    void chat_Go(string,string,char*);
    void inbox(string);
};

void frnd::chat_Go(string uname, string recipient, char *message)
{
    int flag = 0;
    sms[recipient].sender = uname;
    sms[recipient].receiver = recipient;

    map<string, string>::iterator iuser;
    for (iuser = user.begin(); iuser != user.end(); ++iuser)
    {
        if (iuser->first == recipient)
        {
            flag++;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "\nSorry! None User.\n";
        page2(uname);
        return;
    }

    char cuname[20];
    int i;
    for (i = 0; uname[i] != '\0'; ++i)
    {
        cuname[i] = uname[i];
    }
    cuname[i] = '\0';

    strcpy(sms[recipient].mess[sms[recipient].num_of_message], cuname);
    strcat(sms[recipient].mess[sms[recipient].num_of_message], ": ");
    strcat(sms[recipient].mess[sms[recipient].num_of_message], message);

    sms[recipient].num_of_message++;
}

void frnd::inbox(string uname)
{
    cout<<"\nWelcome "<<uname<<" to your Inbox\n\n";
    cout<<"All Messages in your Inbox:\n\n";
    for(int i=0;i<=sms[uname].num_of_message;i++)
    {
        puts(sms[uname].mess[i]);
        cout<<endl<<endl;
    }
}

void frnd::addfriend(string uname)
{
    vector<string>::iterator iv;
    map<string,string>::iterator iuser;
   int uflag=0,flag=0,flag3=0;
 string addname;
 cout<<"\nEnter the name which you want to add in your friend list"<<endl;
 cin>>addname;
 cout<<"\nPlease wait! checking for  "<<addname<<"......\n";
 // waiting time for new mwssage
for(int i=0;i<99999910;)
{
i++;
}
 for(iuser=user.begin();iuser!=user.end();iuser++)
        {
            for(iv=flist.begin();iv!=flist.end();iv++)
            {
               if(*iv==addname)
                    flag3++;
            }
            if(addname==uname)
            {

                uflag++;
                break;
            }



            else if(iuser->first==addname)
             flag++;

}

if(uflag==1 && flag==0 && flag3==0)
    cout<<"\nSorry! Can't add yourself to your friend list\n";
if(flag==1 && uflag==0 && flag3==0)
{
  cout<<"\nFound\t"<<addname<<endl;
  flist.push_back(addname);
  cout<<"\nCongratulations! "<<addname<<" has been added to your friend list\n"<<endl;

}
else if(uflag==0&&flag==0)
    {
    cout<<"\nSorry!! this username does not exist\n";
    }
else if(flag3)
{
    cout<<"\n"<<addname<<" already exists in your friend list\n";
}

}

void frnd::dispfriend(string uname)
{
    int c=0;
    vector<string>::iterator i;
    i=flist.begin();
    cout<<"\nWelcome "<<uname<<" Your Friends are:"<<endl;
    for(;i!=flist.end();i++)
    {
        cout<<"\n"<<*i<<endl;
        c++;
    }
    cout<<endl<<endl<<"\nTotal friends: "<<c;
}

void frnd::unfriend(string uname)
{
    if(flist.empty())
    {
        cout<<"\nFriend list empty..!!\a\n";
    }
    else{
    int c=0,pos=0,flag=0;
    string name;
    cout<<"\nenter the friend name you want to unfriend \n";
    cin>>name;
    vector<string>::iterator i;
    i=flist.begin();

    for(;i!=flist.end();i++)
    {
        c++;
        if(*i==name)
        {
            flag++;
          pos=c-1;
          break;
        }
    }

    i=flist.begin();
    if(pos || flag)
    {
        cout<<"\n Removing "<<name<<" from your friend list..\a\a\a\a\n";
        flist.erase(i+pos);
        cout<<name<<" has been successfully removed from your friend list\n";
    }
    if(flag==0 && pos==0)
    {
        cout<<"\nNo such friend exists in your friend list\n";
    }
}
}
void page1()
{
    int flag = 0;
    int choice;

    cout << "\n\t\t\t Tiny-MESSENGER\n";

    while (true)
    {
        cout << "\nPlease select an option:\n"
             << "  1 - Sign Up\n"
             << "  2 - Sign In\n"
             << "  3 - Exit\n\n";

        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string username, pwd;
                cout << "\nChoose a username: ";
                cin >> username;
                cout << "Choose a password: ";
                cin >> pwd;

                if (user.find(username) != user.end())
                {
                    cout << "\nSorry! Username not available. Please try with a different name.\n";
                }
                else
                {
                    user[username] = pwd;
                    cout << "\nUser registered successfully!\n";
                }

                break;
            }

            case 2:
            {
                string lusername, lpwd;
                cout << "\nEnter your username: ";
                cin >> lusername;
                cout << "Enter your password: ";
                cin >> lpwd;

                if (user.find(lusername) != user.end() && user[lusername] == lpwd)
                {
                    cout << "\nWELCOME " << lusername << "!! You have successfully logged in.\n";
                    flag = 1;
                    page2(lusername);
                }
                else
                {
                    cout << "\nUsername or password is incorrect. Please try again.\n";
                }

                break;
            }

            case 3:
            {
                cout << "\nDisplay\n";
                cout << "\nAll users:\n";
                for (const auto& entry : user)
                {
                    cout << entry.first << "\t" << entry.second << endl;
                }
                break;
            }

            default:
            {
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }

        if (flag == 1)
        {
            break;
        }
    }
}

map<string,frnd> f;
void page2(string uname)
{
    int choice2, choice3;

main_menu:
    cout << string(13, '\n');
    cout << "\t\t\t     WELCOME    " << uname << endl << endl;

    cout << "\n\t    ***********You have to choose from the following menu**********\n";
    cout << "\n1 - Inbox\n2 - Chat\n3 - Friend List\n4 - Add Friend\n5 - Unfriend\n6 - Group Chat\n7 - Log Out\n";
    cin >> choice2;

    switch (choice2)
    {
        case 1:
        {
            f[uname].inbox(uname);
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 2:
        {
            string recipient;
            cout << "\nPlease enter the recipient's name: ";
            cin >> recipient;

            char message[100];
            cout << "\nPlease type your message:\n";
            cin.ignore();
            cin.getline(message, 100);

            f[recipient].chat_Go(uname, recipient, message);
            cout << "\nYour message has been sent.\n";
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 3:
        {
            f[uname].dispfriend(uname);
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 4:
        {
            f[uname].addfriend(uname);
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 5:
        {
            f[uname].unfriend(uname);
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 6:
        {
            char ch;
            vector<string> recipients;
            map<string, string>::iterator iuser;
            vector<string>::iterator irec;

        group:
            int flag = 0;
            string recipient;
            cout << "Enter recipient: ";
            cin >> recipient;

            for (iuser = user.begin(); iuser != user.end(); ++iuser)
            {
                if (iuser->first == recipient)
                {
                    flag++;
                }
            }

            if (!flag)
            {
                cout << "\nSorry! No such user exists.\n";
                goto group;
            }

            recipients.push_back(recipient);
            cout << "Do you want to add more recipients (y/n)? ";
            cin >> ch;

            if (ch == 'y')
            {
                goto group;
            }
            else if (ch == 'n')
            {
                char message[100];
                cout << "\nPlease type your message:\n";
                cin.ignore();
                cin.getline(message, 100);

                for (irec = recipients.begin(); irec != recipients.end(); ++irec)
                {
                    f[*irec].chat_Go(uname, *irec, message);
                }
            }

            cout << "\nYour message has been sent.\n";
            cout << "\nPress any number except '0' to go back to the main menu: ";
            cin >> choice3;

            if (choice3)
                goto main_menu;

            break;
        }
        case 7:
        {
            system("cls");
            cout << "\nYou have been successfully logged out.\n";
            page1();
            break;
        }
        default:
        {
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }
    }
}


int main()
{
page1();
return 0;
}


