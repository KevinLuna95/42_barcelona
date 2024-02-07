SRC_DIR		= src/
OBJ_DIR		= obj/

all:		server client

server:
			make -C src_server

client:
			make -C src_client

clean:
			$(RM) -rf $(OBJ_DIR)
			@make clean -C src_client
			@make clean -C src_server
			@make clean -C libft
			@echo "$(BLUE)all object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@$(RM) -f src_server/server
			@$(RM) -f src_client/client
			@echo "$(CYAN)all executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm