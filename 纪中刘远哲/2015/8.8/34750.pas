const 
	NSIZE = 100000;
	CSIZE = 1000;
var 
	n,c,r,tail,head	:longint;
	s	: array[1..NSIZE] of longint;
	//����sģ��һ��ջ��nΪջ��Ԫ�ظ���
	q	:array[1..CSIZE] of longint;
	//����qģ��һ��ѭ�����У�tailΪ��β���±꣬headΪ��ͷ���±�
	direction,empty :boolean;
	
function previous(k :longint) :longint;
begin
	if direction then
		previous := ((k+c-2) mod c) + 1
	else 
		previous := (k mod c) + 1;
end;

function next(k	:longint)	:longint;
begin
	if direction then 
	    next:=(k mod c )+1  
	else 
		next := ((k+c-2) mod c)+1;
end;

procedure push;
var
	element	:longint;
begin
	read(element);
	if next(head) = tail then
	begin
		inc(n);
		    s[n]:=q[tail]    ;
		tail := next(tail);
	end;
	if empty then

		empty := false
	else
		head := next(head);
	  q[head]   := element;
end;

procedure pop;
begin
	if empty then
	begin
		writeln('Error: the stack is empty!');
		exit;
	end;
	writeln(    q[head]   );
	if tail = head then
    empty := true
	else
	begin
    head := previous(head);
		if n > 0 then
		begin
    	tail := previous(tail);
			   q[tail]    := s[n];
			dec(n);
		end;
	end;
end;

procedure reverse;
var
    temp	:longint;
begin
	if    next(head)    = tail then
	begin
    direction := not direction;
    temp := head;
    head := tail;
    tail := temp;
	end else
      writeln('Error:less than',c,' elements in the stack!');
end;

begin
	assign(input,'3475.in');reset(input);
	
	readln(c);
	n := 0;
	tail := 1;
	head := 1;
	empty := true;
	direction := true;
	repeat
		read(r);
		case r of
			1:push;
			2:pop;
			3:reverse;
		end;
	until r = 0;
end.


