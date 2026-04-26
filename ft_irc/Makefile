# **************************************************************************** #
#                                  FT_IRC                                      #
# **************************************************************************** #

NAME    = ircserv
CXX     = c++
CXXFLAGS= -g -Wall -Wextra -Werror -std=c++98

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

# Directorio de los fuentes
HEADERS		=	NickName.class.hpp \
				HostName.class.hpp \
				UserName.class.hpp \
				ChanName.class.hpp \
				Parser.class.hpp \
				Logger.class.hpp \
				IrcNumerics.hpp \
				IrcMM.class.hpp \
				Client.hpp \
				Channel.class.hpp \


# Lista explícita de fuentes
SRCS = ChanName.class.cpp \
	   HostName.class.cpp \
	   NickName.class.cpp \
	   UserName.class.cpp \
	   Parser.class.cpp \
	   Logger.class.cpp \
	   IrcMM.class.cpp \
	   main.cpp \
       Server.cpp \
       FileDescriptor.cpp \
	   Client.cpp \
	   cmd_admin.cpp \
	   cmd_away.cpp \
	   cmd_cap.cpp \
	   cmd_connect.cpp \
	   cmd_die.cpp \
	   cmd_error.cpp \
	   cmd_info.cpp \
	   cmd_invite.cpp \
	   cmd_join.cpp \
	   cmd_kick.cpp \
	   cmd_kill.cpp \
	   cmd_links.cpp \
	   cmd_list.cpp \
	   cmd_lusers.cpp \
	   cmd_mode.cpp \
	   cmd_mode_user.cpp \
	   cmd_mode_channel.cpp \
	   cmd_motd.cpp \
	   cmd_names.cpp \
	   cmd_nick.cpp \
	   cmd_notice.cpp \
	   cmd_oper.cpp \
	   cmd_part.cpp \
	   cmd_pass.cpp \
	   cmd_ping.cpp \
	   cmd_pong.cpp \
	   cmd_privmsg.cpp \
	   cmd_privmsg_user.cpp \
	   cmd_privmsg_channel.cpp \
	   cmd_quit.cpp \
	   cmd_rehash.cpp \
	   cmd_restart.cpp \
	   cmd_servlist.cpp \
	   cmd_squery.cpp \
	   cmd_squirt.cpp \
	   cmd_stats.cpp \
	   cmd_time.cpp \
	   cmd_topic.cpp \
	   cmd_trace.cpp \
	   cmd_user.cpp \
	   cmd_version.cpp \
	   cmd_who.cpp \
	   cmd_whois.cpp \
	   cmd_whowas.cpp \
	   Channel.class.cpp 


# Objetos correspondientes
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# Regla principal
all: $(NAME)
	rm -rf ~/.config/hexchat/logs/*
	rm -rf ~/.config/hexchat/scrollback/*

# Create objects directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla genérica para compilar objetos
$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar objetos
clean:
	rm -rf $(OBJS_DIR)

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	rm -rf ~/.config/hexchat/logs/*
	rm -rf ~/.config/hexchat/scrollback/*

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re
