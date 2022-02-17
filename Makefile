# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 16:03:11 by moulmado          #+#    #+#              #
#    Updated: 2022/02/16 18:23:34 by moulmado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Mandatory/so_long
BNAME = Bonus/so_long_bonus

INCM = Mandatory/so_long.h
INCB = Bonus/so_long_bonus.h

SRCM = Mandatory/so_long.c\
		Mandatory/so_long_check_next_position_4c_h.c\
		Mandatory/so_long_check_next_position_4c_v.c\
		Mandatory/so_long_check_next_position_4wall_h.c\
		Mandatory/so_long_check_next_position_4wall_v.c\
		Mandatory/so_long_check_next_position_exit_h.c\
		Mandatory/so_long_check_next_position_exit_v.c\
		Mandatory/so_long_collectibles_position.c\
		Mandatory/so_long_exit_position.c\
		Mandatory/so_long_get_imgs.c\
		Mandatory/so_long_get_info.c\
		Mandatory/so_long_getmap.c\
		Mandatory/so_long_imgs_util_1.c\
		Mandatory/so_long_imgs_util_2.c\
		Mandatory/so_long_map_check.c\
		Mandatory/so_long_map_check_utils.c\
		Mandatory/so_long_open_window.c\
		Mandatory/so_long_put_collectibles.c\
		Mandatory/so_long_put_elements.c\
		Mandatory/so_long_put_exit.c\
		Mandatory/so_long_put_walls.c\
		Mandatory/so_long_running_down.c\
		Mandatory/so_long_running_left.c\
		Mandatory/so_long_running_right.c\
		Mandatory/so_long_running_up.c\
		Mandatory/so_long_standing_left.c\
		Mandatory/so_long_standing_right.c\
		Mandatory/so_long_standing.c\
		Mandatory/so_long_utils.c\
		Mandatory/so_long_wall_position.c\
		Mandatory/put_nbr.c\
		Mandatory/so_long_free.c\
		Mandatory/so_long_utils_.c
		
SRCB = Bonus/so_long_bonus.c\
		Bonus/so_long_check_next_position_4c_h.c\
		Bonus/so_long_check_next_position_4c_v.c\
		Bonus/so_long_check_next_position_4wall_h.c\
		Bonus/so_long_check_next_position_4wall_v.c\
		Bonus/so_long_check_next_position_exit_h.c\
		Bonus/so_long_check_next_position_exit_v.c\
		Bonus/so_long_collectibles_position.c\
		Bonus/so_long_exit_position.c\
		Bonus/so_long_get_imgs.c\
		Bonus/so_long_get_info.c\
		Bonus/so_long_getmap.c\
		Bonus/so_long_imgs_util_1.c\
		Bonus/so_long_imgs_util_2.c\
		Bonus/so_long_map_check.c\
		Bonus/so_long_map_check_utils.c\
		Bonus/so_long_open_window.c\
		Bonus/so_long_put_collectibles.c\
		Bonus/so_long_put_elements.c\
		Bonus/so_long_put_exit.c\
		Bonus/so_long_put_walls.c\
		Bonus/so_long_running_down.c\
		Bonus/so_long_running_left.c\
		Bonus/so_long_running_right.c\
		Bonus/so_long_running_up.c\
		Bonus/so_long_standing_left.c\
		Bonus/so_long_standing_right.c\
		Bonus/so_long_standing.c\
		Bonus/so_long_utils.c\
		Bonus/so_long_wall_position.c\
		Bonus/put_nbr.c\
		Bonus/so_long_free.c\
		Bonus/so_long_wasted_v.c\
		Bonus/so_long_wasted_h.c\
		Bonus/so_long_wasted_e.c\
		Bonus/so_long_enemy.c\
		Bonus/so_long_enemy_position.c\
		Bonus/so_long_check_nextposition_4c_e.c\
		Bonus/so_long_check_nextposition_4exit_e.c\
		Bonus/so_long_check_nextposition_e.c\
		Bonus/itoa.c\
		Bonus/so_long_utils_.c
		
OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJM) $(INCM)
	@$(CC) $(OBJM) $(CFLAGS) -lmlx -framework OpenGL -framework Appkit -o $(NAME) 	
	@echo "░██████╗░█████╗░░░░░░░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "██╔════╝██╔══██╗░░░░░░██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "╚█████╗░██║░░██║░░░░░░██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "░╚═══██╗██║░░██║░░░░░░██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "██████╔╝╚█████╔╝█████╗███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "╚═════╝░░╚════╝░╚════╝╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"

clean :
	@rm -rf $(OBJM) $(OBJB)

fclean : clean
	@rm -rf $(NAME) $(BNAME)

re : fclean all

bonus : $(OBJB) $(INCB)
	@$(CC) $(OBJB) $(CFLAGS) -lmlx -framework OpenGL -framework Appkit -o $(BNAME)
	@echo "██████╗░░█████╗░███╗░░██╗██╗░░░██╗░██████╗"
	@echo "██╔══██╗██╔══██╗████╗░██║██║░░░██║██╔════╝"
	@echo "██████╦╝██║░░██║██╔██╗██║██║░░░██║╚█████╗░"
	@echo "██╔══██╗██║░░██║██║╚████║██║░░░██║░╚═══██╗"
	@echo "██████╦╝╚█████╔╝██║░╚███║╚██████╔╝██████╔╝"
	@echo "╚═════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═════╝░"