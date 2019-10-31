#!/usr/bin/perl

$turn = 0;
$task = 100;
$health = 100;
$spirit = 100;
$rest = 0;

#player do anything.
#player can work yourself. health -=10, spirit -=5 task-=taskcard's pow
# taskcard's is all of them.
# cardpow = 10 x 10cards
# cardpow = 5 x 20 cards
# cardpow = -10 x 5cards
# cardpow = 15 x 5 cards
#player can rest yourself. health +=20, spirit +=20,task don't move.
# restcard = 5cards.
#player health and spirit += 10 allturnend.
#player can use anycard.
$p_card = { 10, 20, 5, 5, 5, 15};

#consumer do anything.
#consumer wait player to deliver a product.
#consumer can disturb his work.
# "additional request" ... trush a workcard. x10
# "employee mistake trouble" ... spirit damage 10 x 5
# "angry boss" ... spirit damage 20 x 5
# "earthquake" ... health damage 10, spirit damage 5 x 1
# "discussion for work" ... task -= 5, health -=20 x 9
$c_card = {10,5,5,1,9};
while(1)
{
	#player turn
	if($turn > 60)
	{
		return;
	}
	$turn = $turn + 1;
	if($rest > 0)
	{
		$rest = $rest - 1;
	}

	if($health <= 0)
	{
	}
	$health = $health + 10;
	$spirit = $spirit + 10;
		
	

	
	// player and consumer, put card for them own turn.
	// player work and work, would be finish the task and can deliver a product.
	
	//first, player has 5 cards, consumer has no cards.
	

	
	//second
	
	

	
}
