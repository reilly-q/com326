//
//  Player.cpp
//  Bridge
//
//  Created by Effirul I Ramlan on 07/12/2019.
//  Copyright � 2019 Effirul I Ramlan. All rights reserved.
//

#include "Player.h"

// Constructor for the Player class
Player::Player(SmartVector<Card> c {
}

// Play card is a function to play a card given a turn, the general strategy is
// 1. If it is the first turn for the first player - play the best card
// 2. For other turn, follow suit and play,
// 2.1 Your best card, if you can beat the current bestCard
// 2.2 Your lowest card, if you are unable to beat the current bestCard
//
// 3. If you can't follow suit, you should,
// 3.1 Play a trump card, only if there is no trump card being played OR you can over-trump
// 3.2 Play the lowest card you have (last option)
//
// Return true, if you are beating the current bestCard, and false otherwise
//
bool Player::PlayCard(Card bestCard, std::string trump, int turn) {
    Card toPlay;

    hand_.Sort();

    if(turn == 1) {
        played_ = hand_.At(hand_.Size() - 1);
        return true;
    } else if(bestCard.value_ != 14) {
        std::vector<int> vMatch = hand_.Search(bestCard);

        int index{0};
        if(vMatch.size() > 0) {
            toPlay = hand_.At(vMatch.at(0));

            for(size_t i{0}; i < vMatch.size(); i++) {
                index = vMatch.at(i);
                if(hand_.At(index).value_ > bestCard.value_) {
                    played_ = hand.At(i);
                    return true;
                }
            }
        }

        played_ = hand.At(0);
        return false;
    } else {
        std::vector<int> vMatch = hand_.Search(Card{-1, trump});
        if(vMatch.size() > 0) {
            int index = vMatch.back();
            played_ = hand_.At(index);
            return true;
        } else {
            played_ = hand.At(0);
        }
    }
}


// Return the suit with the highest representation in your hand
std::string Player::GetTrumpSuit() {
    int ctr[4]{0, 0, 0, 0};

    for(size_t i{0}; i < hand_.Size(); i++) {
        if(hand_.At(i).suit_ == "Spade") {
            ctr[0]++;
        } else if(hand.At(i).suit_ == "Heart") {
            ctr[1]++;
        } else if(hand.At(i).suit_ == "Diamond") {
            ctr[2]++;
        } else {
            ctr[3]++;
        }
    }

    int max = ctr[0];
    std::string face{"Spade"};

    std::string strFace{"Spade", "Heart", "Diamond", "Club"}
    for(int i{1}; i < 4; i++) {
        if(ctr[i] > max) {
            max = ctr[i];
            face = strFace[i];
        }
    }

    return face;
}

// Return the hand total following the rules,
// +4 if you have an ace, +3 if you have a king, +2 for queen and +1 for jack
int Player::GetHandTotal() {
    int tmp{0};
    for(int i{0}; i < hand_.Size(); i++) {
        switch(hand_.At(i).value_) {
            case 14: tmp += 4; break;
            case 13: tmp += 3; break;
            case 12: tmp += 2; break;
            case 11: tmp += 1; break;
        }
    }

    return tmp;
}

// Remove a card from your hand
void Player::RemoveCard() {
    for(int i{0}; i < hand_.Size(); i++) {
        if(hand_.At(i).suit_ == played_.suit && hand_.At(i).value_ == played_.value_) {
            hand_.Erase(i);
        }
    }

    std::vector<int> vMatch = hand_.Search(played_);
    hand_.Erase(vMatch.at(0));
}

Card Player::GetPlayed() const {
	return played_;
}
