# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/04/13 21:44:59 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.msg Makefile.vars

# ---
#  General targets
# ---

# Build everything

all: $(TESTS)

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
	$(call qcmd,$(RM) -r $(OUTDIR))
	$(call qcmd,(cd libft && $(MAKE) $@))

# Rebuild

re: fclean all

.PHONY: all mostlyclean mclean clean fclean re

# ---
# Build targets
# ---

libft/libft.a:
	$(call qcmd,(cd libft && $(MAKE) all))

define make-test-rule
$(OUTDIR)/$1: $(OBJDIR)/$1.o
	$(call qcmd,$(MKDIR) -p $$(@D))
	$(call bcmd,ld,$$^,$(LD) $(LDFLAGS) -o $$@ $$^ libft/libft.a $(LDLIB))
$1: libft/libft.a $(OUTDIR)/$1
	$(call qcmd,$(OUTDIR)/$$@)
endef
$(foreach test,$(TESTS), \
	$(eval $(call make-test-rule,$(test))))

define make-test-objs-rule
$(OBJDIR)/$1.o: $(TESTDIR)/$1.c
	$(call qcmd,$(MKDIR) -p $$(@D))
	$(call bcmd,cc,$$<,$(CC) $(CFLAGS) -o $$@ $$^)
endef
$(foreach test,$(TESTS), \
	$(eval $(call make-test-objs-rule,$(test))))

-include $(DEPS)
