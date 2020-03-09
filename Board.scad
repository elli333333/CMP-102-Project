// Board Dimensions
// Min Size = 512
BoardCenter = 512;
BoardX = BoardCenter * 2;
BoardY = BoardCenter * 2;

// Ring Dimensions
RadiusRingBullInner = BoardCenter / 8;
RadiusRingBullOuter = BoardCenter / 4;

RadiusRingTrebleInner = (BoardCenter / 2) - (BoardCenter / 4);
RadiusRingTrebleOuter = BoardCenter /2;

RadiusRingDoubleInner = BoardCenter - (BoardCenter / 8);

RadiusRingOuterBound = BoardCenter -  (BoardCenter /16);

RadiusRingOutOfBounds = BoardCenter;

// Board Box
color(c="black"){
    square(size = [BoardX, BoardY], center=true);
};

//  Out Of Bounds ring
color(c="black"){
    circle(r=RadiusRingOutOfBounds);
};

// Outer Ring/Double Ring
color(c="green"){
    circle(r=RadiusRingOuterBound);
}
color(c="red"){
    circle(r=RadiusRingDoubleInner);
};

// Treble Ring
color(c="yellow"){
    circle(r=RadiusRingTrebleOuter);
};
color(c="green"){
    circle(r=RadiusRingTrebleInner);
};

// Bull Ring
color(c="green"){
    circle(r=RadiusRingBullOuter);
};
color(c="red"){
    circle(r=RadiusRingBullInner);
};