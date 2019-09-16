# introduction and remembering of that shit

## Quick Start
   
### Text paatterns and matches
*   in the website :
    - regular expressions are in brown ` regex `
    - the match are in blue the string regex, witch are match by 
       the previous regex regex
    - string, the text that be match by the regex are green.
    - character class are yellow

### Literal characters 
*   the are the basics of regex, they like `a or b or c...`
*   the specials : \ ^ $ . | ? * + ( ) [ ] {} \
    they need to be escaped.
    
### Character Class / Set
*   the :  [ ]
    - In yellow on the site. 
    - the order in the [] does not matter.
    - match only one char, event there is more inside.
    - with the hyphen, I can select an range of element :
       * ` [0-9] ` will match all decimal char.
       * ` [0-9a-fA-F] ` will match all hexadecimal case insensitively.
       * ` [0-9a-fxA-FX] ` will match all hexadecimal and the letter x.
       * ` q[^a] ` that match any char that are not in the character class, \
                   that will match question but not Iraq because there isn't char to match at his end.

### Shorthand Character Classes
*   ` \d ` match all single digit.
*   ` \w ` match a word : alphanumeric + _ .
*   ` s ` match a whitespace character like space and tab ...
*   be careful, the matches of the shorthand Character depend of the system.

### Non printable char and unicode
*   I can use in my regex `\n \t ...`, or even unicode ` \uFFFF` == euro currency.

### The Dot
*   The dot match all single char apart the \n, 
*   the mode 'dot match all' can make the dot match all char
*   `gr.y` matches gray, grey, gr%y. 
*   Use the dot sparingly (parcimonie), because a Char Class, or negated Char Class \
    is faster and more precise.

### Anchors
*   does not match any char, they match a position 
    - ` ^ `  match start of the line.
    - ` $ `  match end of the line.
    - ` ^b ` match b in bob.
    - ` \b ` match the word boundaries, this is between a char that can be match \w \
        and a char that can't be match be \w.
    - ` \B ` match every position where \b cannot match.
    - I didn't unsderstand that one : \
         \b also matches at the start and/or end of the string if the first and/or last characters in the string are word characters. 
        
### Altercation
*   is equivalent af 'or'.
*   ` cat|dog ` will match cat or dog.
*   alternation has the lowest precedence (order in witch the operator are assessed (evalué)) \
    ` cat|dog food ` will match cat / dog food, to match cat food and dog food, \
    I will create a group : ` (cat|dog) food`.
 
### Repetition
*   ` ? ` make preceding token optional \
    ` colou?r` will match both colour and color.
*   ` * ` tell the engine te attempt to match the preceding token zero or more time.
*   ` + ` tell match one or more times.
*   example match html tag \
    ` <[A-Za-z][A-Za-z0-9]*> ` match all HTML tag without any attributes \
    `<[A-Za-Z0-9]+>` is easy to write, but will match invalid tag like <1>.
*   Define a specific amount of repetition with ` {} `
    - ` \b[1-9][0-9]{3}\b ` match all number between 1000 and 9999
    - ` \b[1-9][0-9]{2,4} ` match all numeber between 100 and 9.9999
    

### Greedy (glouton)  and Lazy Repetition
*   The repetition operator are greedy, they expand the match as far as they can \
    and only give back if they must to satisfy the remainder of the regex.
    place one __? to make it lazy__
    - ` <.+> ` match all <em>first</em>
    - ` <.+?>` match only <em> / </em>
*   better way to do teh last example is without the . is `<[^<>]+>` 
    as the repetition is greedy, and an html tag can contain all stuff but not <>
    I force the engine to get only the themselves

 


     
     