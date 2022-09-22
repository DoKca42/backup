/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@k0r3p2.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:21:07 by loculy            #+#    #+#             */
/*   Updated: 2022/09/10 14:45:59 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_abs(int n)
{
    if (n < 0)
        return (n * -1);
    else
        return (n);
}

void    ft_solve(char *tab, int nbq, int *tot)
{
    int    i;
    int    j;

    if (nbq == 6)
    {
        nbq = 0;
        //while (nbq < 10)
        //    ft_putchar(tab[nbq++] + '0');
        //ft_putchar('\n');
        printf("\n\n");
        (*tot)++;
        return ;
    }
    i = -1;
    while (++i < 6)
    {
        j = 0;
        while (j < nbq && i != tab[j] && ft_abs(tab[j] - i) != nbq - j)
        {   
            //printf("%d | %d | %d | %d | %d \n",j, nbq, i, ft_abs(tab[j] - i), nbq - j );
            j++;
            }
        if (j >= nbq)
        {
            tab[nbq] = i;
            ft_solve(tab, nbq + 1, tot);
        }
    }
}

int    ft_ten_queens_puzzle(void)
{
    int        nbq;
    char    tab[6];
    int        tot;

    nbq = 0;
    tot = 0;
    ft_solve(tab, nbq, &tot);
    return (tot);
}
int main() {
  ft_ten_queens_puzzle();
  return 0;
}