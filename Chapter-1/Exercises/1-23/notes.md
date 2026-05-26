It seems that I will need to create a state machine for this exercise, and due to the complexity, notes are going to need to be taken.

The states required are

 - NORMAL
 - SAW_SLASH
 - IN_COMMENT
 - COMMENT_SAW_STAR
 - IN_STRING
 - STRING_ESCAPE
 - IN_CHAR
 - CHAR_ESCAPE
 - IN_LINE_COMMENT

**State table for 1-23**

|State|Input|Next State|Output Action|
|------|------|------|------|
|NORMAL|/|SAW_SLASH|hold (don't print yet)|
|NORMAL|"|IN_STRING|print "|
|NORMAL|'|IN_CHAR|print '|
|NORMAL|other|NORMAL|print other|
|SAW_SLASH|*|IN_COMMENT|discard held /|
|SAW_SLASH|/|IN_LINE_COMMENT|discard held /|
|SAW_SLASH|"|IN_STRING|print held /, print "|
|SAW_SLASH|'|IN_CHAR|print held /, print '|
|SAW_SLASH|other|NORMAL|print held /, print other|
|IN_LINE_COMMENT|\n|NORMAL|print \n|
|IN_LINE_COMMENT|other|IN_LINE_COMMENT|nothing|
|IN_COMMENT|*|COMMENT_SAW_STAR|nothing|
|IN_COMMENT|other|IN_COMMENT|nothing|
|COMMENT_SAW_STAR|/|NORMAL|nothing|
|COMMENT_SAW_STAR|*|COMMENT_SAW_STAR|nothing|
|COMMENT_SAW_STAR|other|IN_COMMENT|nothing|
|IN_STRING|"|NORMAL|print "|
|IN_STRING|`\|STRING_ESCAPE|print `\|
|IN_STRING|other|IN_STRING|print it|
|STRING_ESCAPE|any|IN_STRING|print it|
|IN_CHAR|'|NORMAL|print '|
|IN_CHAR|`\|CHAR_ESCAPE|print `\|
|IN_CHAR|other|IN_CHAR|print it|
|CHAR_ESCAPE|any|IN_CHAR|print it|

We will be using switch statements to build the state machine.

    switch(state){
		case NORMAL:
		    if(c==example)
			    ...
			else if(c==example2)
				...
			else
				...
			break;
		case SAW_SLASH:
			...
			break;
	}
and continue on as so.