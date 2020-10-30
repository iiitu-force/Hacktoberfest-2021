/*Problem : Extraxting numbers out of string.
eg -
Input : "A string with number 68 and 79."
Output : Array consisting of number 68 and 79.
*/

var str = "A string with number 68 and 79.";

var container = str.split(" ")
                .filter(value => {
                    return !isNaN(value);
                }).map(value => {
                    return parseFloat(value);
                });

console.log(container);