# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/04/12 21:23:56 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.msg Makefile.vars

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

# Mostly clean (clean everything without the end result)

mostlyclean:
	$(call rmsg,Removing object folder ($(OBJDIR)))
	$(call qcmd,$(RM) -r $(OBJDIR))
	$(call qcmd,(cd libft && $(MAKE) clean))

mclean: mostlyclean

clean: mclean

# Clean everything

fclean: mostlyclean
	$(call rmsg,Removing the output binary ($(NAME)))
	$(call qcmd,$(RM) $(NAME))
	$(call qcmd,(cd libft && $(MAKE) $@))

# Rebuild

re: fclean all

.PHONY: all mostlyclean mclean clean fclean re

# ---
# Build targets
# ---

libft/libft.a:
	$(call qcmd,(cd libft && $(MAKE) all))

$(NAME): $(OBJS) libft/libft.a
	$(call bcmd,ld,$^,$(LD) $(LDFLAGS) -o $@ $^ $(LDLIB))

$(OBJDIR)/%.o: %.c
	$(call qcmd,$(MKDIR) -p $@D)
	$(call bcmd,cc,$<,$(CC) $(CFLAGS) -I. -o $@ $<)

.PHONY: libft/libft.a

-include $(DEPS)
