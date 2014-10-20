{
	ashish1610
	this is my second attempt to write pascal code
}
program twodogs;
var
	n,k,i,ans:longint;
	found:integer;
	position:array[0..1000005] of longint;
	ar:array[0..500005] of longint;
begin
	randomize;
	read(n);
	read(k);
	for i:=0 to 1000005 do
	begin
		position[i]:=0;
	end;
	for i:=0 to n-1 do
	begin
		read(ar[i]);
	end;
	ans:=0;
	found:=0;
	for i:=0 to (n div 2)-1 do
	begin
		if (((ar[i]<k) and (position[k-ar[i]]=1)) or ((ar[n-1-i]<k) and (position[k-ar[n-1-i]]=1)) or ((ar[i]+ar[n-1-i]=k))) then
		begin
			if (not(2*ar[i]=k) and not(2*ar[n-1-i]=k)) then
			begin
				found:=1;
				ans:=i+1;
				break;
			end;
		end;
		position[ar[i]]:=1;
		position[ar[n-1-i]]:=1;
	end;
	if (((n mod 2)=1) and (found=0)) then
	begin
		if((position[k-ar[n div 2]]=1) and (not(2*ar[n div 2]=k))) then
		begin
			if(k>ar[n div 2]) then
			begin
				found:=1;
				ans:=(n div 2)+1;
			end;
		end;
	end;
	if(found=1) then
	begin
		writeln(ans);
	end
	else
	begin
		writeln('-1');
	end;
end.
