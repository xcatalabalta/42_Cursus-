#ifndef CHANNEL_CLASS_HPP
# define CHANNEL_CLASS_HPP
// includes from project
#include "ChanName.class.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "IrcMM.class.hpp"

// includes extra
#include <sys/socket.h>
#include <vector>

/*
Protocol summary
Channel Characteristics: name, properties and current members
Channel names are case insensitive.
The exact syntax of a channel name is defined in "IRC Server Protocol"

Channel operators are identified by the '@' symbol next to their
nickname whenever it is associated with a channel (i.e., replies to
the NAMES, WHO and WHOIS commands).
A server MUST NOT allow the creation of a new channel if another
channel with the same short name exists; or if another channel with
the same short name existed recently AND any of its member(s) left
because of a network split.  Such channel ceases to exist after last
user leaves AND no other member recently left the channel because of
a network split.

*/


class Channel
{
	private:
		std::string 			m_channel_name;//ChanName
		bool 					m_invite_only;
		bool 					m_topic_restrict;
		std::string 			m_topic;
		bool 					m_key_required;
		std::string 			m_key;
		int 					m_limit;
		int 					m_size;
		std::vector<Client*> 	m_members;
		std::vector<Client*>	m_admins;
		std::vector<Client*> 	m_invited;

		static IrcMM _mm ;

	public:
	// Ortodox class
		Channel();
		~Channel();
		Channel(Channel const &src);
		Channel(const std::string &name);
		Channel (const ChanName &chan_name);
	// Operators	
	Channel &operator=(Channel const &src);

	// General Setters
	void SetChannelName(std::string name);
	void SetInvitOnly();
	void UnsetInvitOnly();
	void SetTopicRestrict();
	void UnsetTopicRestrict();
	void SetTopic(std::string topic);
	void SetKeyRequired(std::string key);
	void UnsetKeyRequired();
	void SetLimit(int limit);
	void UnsetLimit();

	// Client management
	bool AddMember(Client* newMember);
	void RemoveMember(Client* member);
	bool AddAdmin(Client* newAdmin);
	void RemoveAdmin(Client* admin);
	bool AddInvite(Client * newInvite);

	// Auxiliar function for outside management
	bool isAdmin(Client* client) const;
	bool isMember(Client* client) const;
	bool isInvited(Client* client) const;

	// Getters
	const std::string& getName() const;
	const std::string& getTopic() const;
    const std::string& getKey() const;
	const std::string getModes(bool isUser) const;//Creation

    bool isInviteOnly() const;
    bool isTopicRestricted() const;
    bool hasUserLimit() const;
    bool isKeyProtected() const;
    const int& getUserLimit() const;
	const int& getSizeChannel() const;
    std::vector<Client*> getMembers();
	std::vector<Client*> getAdmins();
	std::vector<Client*> getInvited();

	// Methods


	// Broadcast
	void broadcastMessage(const std::string& ircMsg, Client* exclude = 0);
	void sendToall(const std::string& ircMsg);

};


#endif