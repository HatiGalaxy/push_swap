#include "push_swap.h"

// MAX 5 FONKSIYON KURALINA UYGUN
// 1. Kelime Sayımı
static int ft_word_count(const char *s)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != ' ' && s[i] != '\t')
        {
            count++;
            while (s[i] && s[i] != ' ' && s[i] != '\t')
                i++;
            continue;
        }
        i++;
    }
    return (count);
}

// 2. Bölünmüş Diziyi Temizleme
static char **ft_free_split_array(char **arr, int i)
{
    while (i-- > 0)
        free(arr[i]);
    free(arr);
    return (NULL);
}

// 3. Kelimeyi Ayırma
static char *ft_get_word(const char *s, int *start)
{
    int		len;
    int		i;
    char	*word;

    while (s[*start] == ' ' || s[*start] == '\t')
        (*start)++;
    
    len = 0;
    i = *start;
    while (s[i] && s[i] != ' ' && s[i] != '\t')
    {
        len++;
        i++;
    }
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = s[*start + i];
        i++;
    }
    word[len] = '\0';
    *start += len;
    return (word);
}

// 4. Ana Split Fonksiyonu
char **ft_split_args(const char *s)
{
    char	**arr;
    int		word_count;
    int		i;
    int		start;

    if (!s)
        return (NULL);
    word_count = ft_word_count(s);
    arr = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!arr)
        return (NULL);

    i = 0;
    start = 0;
    while (i < word_count)
    {
        arr[i] = ft_get_word(s, &start);
        if (!arr[i])
            return (ft_free_split_array(arr, i));
        i++;
    }
    arr[word_count] = NULL;
    return (arr);
}