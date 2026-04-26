#include "Channel.class.hpp"
IrcMM Channel::_mm =  IrcMM();

Channel::Channel()
{
	m_channel_name = "";
	m_invite_only = false;
	m_topic_restrict = false;
	m_topic = "";
	m_key_required = false;
	m_key = "";
	m_limit = 0;
	m_size = 0;
}

Channel::~Channel()
{
	this->m_members.clear();
	this->m_admins.clear();
	this->m_invited.clear();
	return ;
}

Channel::Channel(Channel const &src)
{
	m_channel_name = src.m_channel_name;
	m_invite_only = src.m_invite_only;
	m_topic_restrict = src.m_topic_restrict;
	m_topic = src.m_topic;
	m_key_required = src.m_key_required;
	m_key = src.m_key;
	m_limit = src.m_limit;
	m_members = src.m_members;
	m_admins = src.m_admins;
	m_invited = src.m_invited;
	m_size = src.m_size;
}

Channel &Channel::operator=(Channel const &src)
{
	if (this != &src)
	{
		m_channel_name = src.m_channel_name;
		m_invite_only = src.m_invite_only;
		m_topic_restrict = src.m_topic_restrict;
		m_topic = src.m_topic;
		m_key_required = src.m_key_required;
		m_key = src.m_key;
		m_limit = src.m_limit;
		if (m_admins.size() > 0)
		{
			m_admins.clear();
			m_admins = src.m_admins;
		}
		if (m_members.size() > 0)
		{
			m_members.clear();
			m_members = src.m_members;
			m_size = src.m_size;
		}
		if (m_invited.size() > 0)
		{
			m_invited.clear();
			m_invited = src.m_invited;
		}
	}
	return (*this);
}

Channel::Channel(const std::string &name)
{
	m_channel_name = name;
	m_invite_only = false;
	m_topic_restrict = false;
	m_topic = "";
	m_key_required = false;
	m_key = "";
	m_limit = 0;
	m_size = 0;
}

Channel::Channel(const ChanName &chan_name)//not in use
{
	m_channel_name = chan_name.get();
	m_invite_only = false;
	m_topic_restrict = false;
	m_topic = "";
	m_key_required = false;
	m_key = "";
	m_limit = 0;
	m_size = 0;
}

// Seters
void Channel::SetChannelName(std::string name)
{
	this->m_channel_name = name;
}

void Channel::SetInvitOnly()
{
	this->m_invite_only = true;
}

void Channel::UnsetInvitOnly()
{
	this->m_invite_only = false;
}

void Channel::SetTopicRestrict()
{
	this->m_topic_restrict = true;
}

void Channel::UnsetTopicRestrict()
{
	this->m_topic_restrict = false;
}

void Channel::SetTopic(std::string topic)
{
	this->m_topic = topic;
}

void Channel::SetKeyRequired(std::string key)
{
	this->m_key_required = true;
	this->m_key = key;
	
}

void Channel::UnsetKeyRequired()
{
	this->m_key_required = false;
	this->m_key = "";
}

void Channel::SetLimit(int limit)
{
	if (limit >= 1)
		this->m_limit = limit;
}
	
void Channel::UnsetLimit()
{
	this->m_limit = 0;
}

// Client Management

bool Channel::AddMember(Client *newMember)
{
	for (std::vector<Client*>::iterator it = m_members.begin(); it != m_members.end(); ++it)
	{
		if ((*it)->getNick() == newMember->getNick())
		{
			return (true);
		}
	}
	m_members.push_back(newMember);
	m_size++;
	if (m_members.size() == 1)
	{
		this->AddAdmin(newMember);
	}
	return (true);
}

void Channel::RemoveMember(Client* member)
{
	/*
	std::string msg;
	//
	std::vector<Client*>::iterator it = m_members.begin();
	for (; it != m_members.end(); ++it)
	{
		if ((*it)->getNick() == member->getNick())
		{
			break;
		}
	}
	*/
	/*
	// // Buscar al miembro por puntero (no por nickname). Mas eficiente.
    std::vector<Client*>::iterator it = std::find(m_members.begin(), 
                                                    m_members.end(), 
                                               		member);
	*/
	/*
	if (it != m_members.end())
	{
		if (this->isAdmin(member))
		{
			this->RemoveAdmin(member);
			//m_members.erase(it);
			//m_size--;
			if(m_size > 1 && m_admins.size() == 1)
			{
				std::vector<Client*>::iterator pit = m_members.begin();
				if (it == pit)
				{
					++pit;
				}
				this->AddAdmin(*pit);
				msg = ":" + (*it)->getNick() + "!" +  (*it)->getUser() + "@" + (*it)->getHost() + " MODE " + m_channel_name + " +o " + (*pit)->getNick();
				this->broadcastMessage(msg, NULL);
			}
			//this->RemoveAdmin(member);
		}
		m_members.erase(it);
		m_size--;
		//if (msg.size() > 0)
		//this->broadcastMessage(msg, NULL);
	}
	*/
	/*
	if (it != m_members.end())
	{
		if (this->isAdmin(member))
			this->RemoveAdmin(member);
		m_members.erase(it);
		m_size--;
	}
	if (m_size > 0 && m_admins.size() == 0)
	{
		it = m_members.begin();
		this->AddAdmin(*it);
		std::string msg = ":" + (*it)->getNick() + "!" +  (*it)->getUser() + "@" + (*it)->getHost() + " MODE " + m_channel_name + " +o " + (*it)->getNick();
    	this->broadcastMessage(msg, NULL);
	}
	*/
	std::vector<Client*>::iterator it = std::find(m_members.begin(), 
                                                    m_members.end(), 
                                               		member);
	std::string msg = ":" + (*it)->getNick() + "!" +  (*it)->getUser() + "@" + (*it)->getHost();
	if (it != m_members.end())
	{
		if (this->isAdmin(member))
			this->RemoveAdmin(member);
		m_members.erase(it);
		m_size--;
	}
	if (m_size > 0 && m_admins.size() == 0)
	{
		it = m_members.begin();
		this->AddAdmin(*it);
		msg += " MODE " + m_channel_name + " +o " + (*it)->getNick();
    	this->broadcastMessage(msg, NULL);
	}
}

bool Channel::AddAdmin(Client *newAdmin)
{

	for (std::vector<Client*>::iterator it = m_admins.begin(); it != m_admins.end(); ++it)
	{
		if ((*it)->getNick() == newAdmin->getNick())
		{
			return (false);
		}

	}
	m_admins.push_back(newAdmin);
	return (true);
}

void Channel::RemoveAdmin(Client *admin)
{
	//std::string msg;
	std::vector<Client*>::iterator it = m_admins.begin();
	for (; it != m_admins.end(); ++it)
	{
		if ((*it)->getNick() == admin->getNick())
		{
			break;
		}
	}
	if (it != m_admins.end())
	{
		m_admins.erase(it);
		return ;
	}
	else
	{
		return ;
	}
}

bool Channel::isAdmin(Client* client) const
{
	std::vector<Client*>::const_iterator it = m_admins.begin();
	for (; it != m_admins.end(); ++it)
	{
		if ((*it)->getNick() == client->getNick())
		{
			return (true);
		}
	}
	return (false);
}

bool Channel::isMember(Client* client) const
{
	std::vector<Client *>::const_iterator it = m_members.begin();
	for (; it != m_members.end(); ++it)
	{
		if ((*it)->getNick() == client->getNick())
		{
			return (true);
		}
	}
	return (false);
}

bool Channel::isInvited(Client* client) const
{
	std::vector<Client *>::const_iterator it = m_invited.begin();
	for (; it != m_invited.end(); ++it)
	{
		if ((*it)->getNick() == client->getNick())
		{
			return (true);
		}
	}
	return (false);
}

const std::string& Channel::getName() const
{
	return (m_channel_name);
}

bool Channel::isTopicRestricted() const
{
	return (m_topic_restrict);
}

const std::string& Channel::getTopic() const
{
	return (m_topic);
}

//
const std::string Channel::getModes(bool isUser) const
{
	std::string modes = "+";
	std::string params = "";
	if (m_topic_restrict)
		modes += "t";
	if (m_invite_only)
		modes += "i";
	if (m_key_required)
	{
		modes += "k";
		if (isUser)
			params += m_key;
	}
	if (m_limit != 0)
	{
		modes += "l";
		if (!params.empty())
			params +=" ";
		std::stringstream ss;
		ss << m_limit;
		params += ss.str();
	}
	//modes += "o";//not a channel characteristic
	std::string response;
	if (params.empty())
		response = modes;
	else
		response = (modes + " " + params);
	
	return (response);
}

bool Channel::isInviteOnly() const
{
	return (m_invite_only);
}

bool Channel::isKeyProtected() const
{
	return (m_key_required);
}

const std::string& Channel::getKey() const
{
	return (m_key);
}

bool Channel::hasUserLimit() const
{
	return (m_limit != 0);
}

const int& Channel::getUserLimit() const
{
	return (m_limit);
}

const int&	 Channel::getSizeChannel() const
{
	return (m_size);
}

std::vector<Client*> Channel::getMembers()
{
	return (m_members);
}

std::vector<Client*> Channel::getAdmins()
{
	return (m_admins);
}

std::vector<Client*> Channel::getInvited()
{
	return (m_invited);
}

//Broadcast
void Channel::broadcastMessage(const std::string& ircMsg, Client* exclude)
{
    for (size_t i = 0; i < m_members.size(); ++i)
    {
        if (m_members[i] != exclude)
		{
            m_members[i]->enqueueIrcMessage(ircMsg);
		}
    }
}

//noy used
void Channel::sendToall(const std::string& ircMsg)
{
	for (size_t i = 0; i < m_members.size(); ++i)
    {
		m_members[i]->enqueueIrcMessage(ircMsg);
	}
}

bool Channel::AddInvite(Client * newInvite)
{
	m_invited.push_back(newInvite);
	return (true);
}