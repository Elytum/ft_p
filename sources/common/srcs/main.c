#include <string.h>
#include <common.h>
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <message.h>

int				main(void)
{
	char		message[] = "Ceci est un test";
	char		*coded;
	size_t		coded_len;	
	t_message	*decoded;

	ft_code_message(S_IFTEXT, message, &coded, &coded_len);
	decoded = ft_decode_message(coded, coded_len);
	printf("Message : error = %i, kind = %i, len = %zu, content = [%s]\n", decoded->error, decoded->kind, decoded->len, decoded->content);
	return(0);
}