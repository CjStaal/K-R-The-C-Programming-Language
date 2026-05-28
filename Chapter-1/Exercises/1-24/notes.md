It seems that I will need to create a state machine for this exercise, and due to the complexity, notes are going to need to be taken.
This is the same code as 1-23. The difference is we are also going to be putting the backets etc in to a stack. This stack will check if they match. If they do not, then the file fails.
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

**State table for 1-24**

|State|Input|Next State|Output Action|
|------|------|------|------|
|NORMAL|/|SAW_SLASH|nothing|
|NORMAL|"|IN_STRING|nothing|
|NORMAL|'|IN_CHAR|nothing|
|NORMAL|other|NORMAL|nothing|
|SAW_SLASH|*|IN_COMMENT|nothing|
|SAW_SLASH|/|IN_LINE_COMMENT|nothing|
|SAW_SLASH|"|IN_STRING|nothing|
|SAW_SLASH|'|IN_CHAR|nothing|
|SAW_SLASH|other|NORMAL|nothing|
|IN_LINE_COMMENT|\n|NORMAL|nothing|
|IN_LINE_COMMENT|other|IN_LINE_COMMENT|nothing|
|IN_COMMENT|*|COMMENT_SAW_STAR|nothing|
|IN_COMMENT|other|IN_COMMENT|nothing|
|COMMENT_SAW_STAR|/|NORMAL|nothing|
|COMMENT_SAW_STAR|*|COMMENT_SAW_STAR|nothing|
|COMMENT_SAW_STAR|other|IN_COMMENT|nothing|
|IN_STRING|"|NORMAL|nothing|
|IN_STRING| \ |STRING_ESCAPE|nothing|
|IN_STRING|other|IN_STRING|nothing|
|STRING_ESCAPE|any|IN_STRING|nothing|
|IN_CHAR|'|NORMAL|nothing|
|IN_CHAR| \ |CHAR_ESCAPE|nothing|
|IN_CHAR|other|IN_CHAR|nothing|
|CHAR_ESCAPE|any|IN_CHAR|nothing|

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

For the stack, we will just use an array for now, as that is what has been covered so far.

